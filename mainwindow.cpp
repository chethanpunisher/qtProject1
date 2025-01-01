#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>
#include <QtMath>  // For sine wave calculations
#include <QTimer>
#include <QFileDialog>
#include <QCompleter>
#include <elementscontainer.h>
#include <QRegularExpression>
#include <QInputDialog>
#include <QPointF>
#include <cmath>

int MainWindow::x = 0;
QString jsonFilePath = "sampleData.json";
JsonManager jsonManager(jsonFilePath);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    resultLabel(new QLabel("Search results will appear here.", this)),
    completer(new QCompleter(this)),
    plotWindow(nullptr),
    xlsxDoc(new QXlsx::Document(this)),
    serialComm(new SerialComm(this)),
    xlsx(new QXlsx::Document(this)),
    ec(nullptr)
{
    dataParser = new DataParser(this);
    excelHandler = new ExcelHandler(this);
    number = 0;
    sc = 0;
    ui->setupUi(this);
    initUI();
    excelInit();
    flg = false;
    opFlg = false;
    // Setup Serial Port
    torqueFlg = false;
    portFlg = true;
    parametersConfig = false;
    comConfig = false;
    saveEn = false;
    //ui->lineEdit_sampleName->setStyleSheet("background-color: #FFDDC1");
    ui->comboBox_mode->addItem("Automatic");
    ui->comboBox_mode->addItem("Manual");
    //ui->lineEdit_sampleName->setStyleSheet("border: 2px solid blue; border-radius: 5px;");
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateComPorts);
    timer->start(2000);  // Update every 100ms
    //connect(ui->comboBox_comPort, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxIndexChanged);
    connect(ui->comboBox_mode, &QComboBox::currentIndexChanged, this, &MainWindow::on_comboBox_mode_currentIndexChanged1);
    connectionMonitorTimer = new QTimer(this);
    loadLabelUpdate = new QTimer(this);
    connect(connectionMonitorTimer, &QTimer::timeout, this, &MainWindow::updateTimeLapse);
    connect(loadLabelUpdate, &QTimer::timeout, this, &MainWindow::loadLabelUp);
    loadLabelUpdate->start(1000);
    //connect(serialNew, &SerialComm::readyRead, this, &MainWindow::readSerialData);
    connect(serialComm, &SerialComm::dataReceived, dataParser, &DataParser::parseData);
    connect(serialComm, &SerialComm::errorOccurred, this, &MainWindow::onSerialPortError);
    connect(dataParser, &DataParser::loadDataParsed, this, &MainWindow::updateLoadValue);
    connect(dataParser, &DataParser::cycleCountParsed, this, &MainWindow::updateCycleCount);
    columnCount = 0;
    updateComPorts();
    exFlg = false;
    timeOutNum = 0;
    startFlg = false;
    mode = false;
    caseCount = 0;
    f_x = 0;
    loadComboBox();
    comboFlg = false;
    //xlsx = new QXlsx::Document(this);
    graphFlg = false;
}

MainWindow::~MainWindow()
{
    //delete chart;
    //foreach (QLineSeries *p, series) {
    //    delete  p;
    //}

    //if (plotWindow)
    //  delete plotWindow;
    //qDebug() << "~MainWindow()";
    //delete ui;
}

void MainWindow::initUI()
{
    ser = new QLineSeries();
    series.append(ser);

    chart = new QChart();
    chart->addSeries(ser);
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle("LOAD vs TIME");
    chart->axisY()->setTitleText("LOAD in Ton");
    chart->axisX()->setTitleText("TIME in Sec");
    chartView = new QChartView(chart);
    chartView->chart()->setTheme(QChart::ChartThemeDark);
    chartView->setRenderHint(QPainter::Antialiasing);

    //ui->gridLayout->addWidget(chartView, 2, 0, 2, 10);
    ui->verticalLayout_5->addWidget(chartView);

    updateAxis();

    series[0]->setColor(QColor(255, 128, 0));
}

void MainWindow::updateAxis()
{
    chart->axisX()->setRange(0, 5);
    chart->axisY()->setRange(-250, 250);  // Sine wave typically ranges between -1 and 1
}

void MainWindow::updateSineWave()
{
    x += 1;

    double amplitude = 1.0;
    double frequency = 1;  // Adjust frequency as needed

    double y = x;

    series[0]->append(x, y);
}

void MainWindow::on_comboBoxADCRes_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);  // Not needed for sine wave, but kept for future use
    updateAxis();
}

void MainWindow::on_comboBoxChannel_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);  // Not needed for sine wave, but kept for future use
    foreach (QLineSeries *p, series) {
        chart->removeSeries(p);
        delete  p;
    }
    series.clear();

    QLineSeries *ser = new QLineSeries();
    chart->addSeries(ser);
    series.append(ser);

    chart->createDefaultAxes();

    updateAxis();
}

void MainWindow::on_EXIT_clicked()
{
    delete chart;
    foreach (QLineSeries *p, series) {
        delete  p;
    }

    qDebug() << "~MainWindow()";
    delete ui;
}


void MainWindow::on_pushButton_start_clicked()
{
    if(devState == devInitState){
        if(parametersConfig && comConfig){
            flg = true;
            QString str1;
            QString command;

            if(en){
                if(comboFlg){
                    // Save the Excel file to the selected path
                    if (xlsx->saveAs(excFilePath)) {
                        //QMessageBox::information(nullptr, "Success", "Excel file created successfully!");
                    } else {
                        QMessageBox::critical(nullptr, "Error", "Failed to create Excel file.");
                    }
                    comboFlg = false;
                }


                //QXlsx::Document xlsx(excFilePath);
                excelHandler->loadExistingExcelFile(excFilePath);
                excelInit();


                ui->label_sampleName->setText(sN);
                str1 = frq;
                ui->label_frequency->setText(str1);
                command = "set frequency " + str1 + "\n";
                writeSerial(command);
                int l;
                int g;
                if(modSp.toFloat() < 10){
                    l = (modSp.toFloat()*10);
                    l = l%10;
                    g = (modAmp.toFloat()*10);
                    g = g%10;
                }
                else{
                    l = modSp.toFloat();
                    l = l%10;
                    g = modAmp.toFloat();
                    g = g%10;
                }

                int temp = g + l;
                qDebug()<<"temp -- "<<temp;
                str1 = amp;//ui->lineEdit_amplitude->text();
                ui->label_amplitude->setText(modSp);
                command = "set amplitude " + str1 + "\n";
                chart->axisY()->setRange(0, (str1.toInt()+sP.toInt())/1000 + (float)temp/10);
                writeSerial(command);
                qDebug()<<command;

                str1 = sP;//ui->lineEdit_setPoint->text();
                ui->label_setPoint->setText(modAmp);
                command = "set point " + str1 + "\n";
                writeSerial(command);
                qDebug()<<command;

                str1 = sC;//ui->lineEdit_stopCycle->text();
                ui->label_stopCycle->setText(str1);
                command = "stop cycle " + str1 + "\n";
                sc = str1.toInt();
                writeSerial(command);
                startTimer();
                deviceState |= START_OPERATION;
                startFlg = true;

                if(xlsx == nullptr){
                    xlsx = new QXlsx::Document;
                }

                str1 = "1";//ui->lineEdit_stopCycle->text();
                command = "set mode " + str1 + "\n";
                writeSerial(command);
                saveEn = true;

                QPair<QString, QString> dateTime = getCurrentDateAndTime();
                bool qwe = jsonManager.addParameter(sN, "startTime", dateTime.second);
                bool sdf = jsonManager.addParameter(sN, "startDate", dateTime.first);
            }
            else{
                QMessageBox::warning(nullptr, "Input Error", "Please enter the parameters");
                flg = false;
            }
        }
        else{
            QMessageBox::warning(nullptr, "Input Error", "Please enter the parameters and com port");
        }
    }
    {
        //QMessageBox::warning(nullptr, "Input Error", "Device initialization failed");
    }
}

void MainWindow::on_pushButton_open_clicked()
{
    //plotWindow = new PlotWindow();  // Create a new instance each time
    //plotWindow->setAttribute(Qt::WA_DeleteOnClose);  // Ensure the window is deleted when closed
    //plotWindow->show();
    analysisPlot = new AnalysisPlot();
    //analysisPlot->setAttribute(Qt::WA_DeleteOnClose);
    analysisPlot->show();
}


void MainWindow::excelInit(){
    // Set the header for columns
    //xlsx->write("A1", "Sl No");
    //xlsx->write("B1", "Sample");
    excelHandler->writeValue(1,1,"Sl No");
    excelHandler->writeValue(1,2, "Sample");
}


void MainWindow::excelWrite(int x, int y){
    // Create a new Excel document

    QString slNo = QString::number(x);
    QString sample = QString::number(y);
    long xTemp = x%800000;
    if(xTemp == 0){
        if(exFlg){
            columnCount += 2;
            //xlsx->write(1,1+ columnCount,"Sl No");
            //xlsx->write(1,2+ columnCount,"Sample");
            excelHandler->writeValue(1,1+columnCount,"Sl No");
            excelHandler->writeValue(1,2+columnCount, "Sample");
        }
        exFlg = true;
    }
    // Write data to the Excel sheet
    //xlsx->write(xTemp + 2, 1 + columnCount, slNo);   // Sl No column (Column A)
    //xlsx->write(xTemp + 2, 2 + columnCount, sample); // Sample column (Column B)
    excelHandler->writeValue(xTemp + 2, 1 + columnCount, slNo);
    excelHandler->writeValue(xTemp + 2, 2 + columnCount, sample);
    //xlsxDoc->write(x + 1, 1, slNo);   // Sl No column (Column A)
    //xlsxDoc->write(x + 1, 2, sample); // Sample column (Column B)
}


void MainWindow::on_pushButton_stop_clicked()
{
    QString str1;
    QString command;
    str1 = "1";//ui->lineEdit_setPoint->text();
    command = "stop " + str1 + "\n";
    writeSerial(command);
    deviceState |= STOP_OPERATION;
    //serialNew->writeToSerial(command);
}


void MainWindow::on_pushButton_delete_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Open Excel File",
                                                    QDir::homePath(),
                                                    "Excel Files (*.xlsx)");

    // Create a QFile object
    QFile file(filePath);

    // Check if the file exists
    if (file.exists()) {
        // Attempt to remove the file
        if (file.remove()) {
            //qDebug() << "File deleted successfully.";
            QMessageBox::information(nullptr, "Success", "Excel file deleted successfully!");
        } else {
            //qDebug() << "Failed to delete the file.";
            QMessageBox::warning(nullptr, "Cancelled", "Failed to delete");
        }
    } else {
        QMessageBox::warning(nullptr, "Cancelled", "file does not exist.");
    }
}

bool MainWindow::isItemInComboBox(const QString& itemText) {
    if (!ui->comboBox_existingParamSelec) {
        qWarning() << "ComboBox is null!";
        return false;
    }

    // Iterate through all items in the combo box
    for (int i = 0; i < ui->comboBox_existingParamSelec->count(); ++i) {
        if (ui->comboBox_existingParamSelec->itemText(i) == itemText) {
            return true;  // Item found
        }
    }

    return false;  // Item not found
}

void MainWindow::parameters(int index){
    sindex = index;
    qDebug()<<index;
    QJsonObject jsonObject1 = jsonManager.loadParametersByIndex(index);
    sN = jsonObject1.value("sampleName").toString();
    frq = QString::number(jsonObject1.value("frequency").toDouble());
    amp = QString::number(jsonObject1.value("amplitude").toInt() - ((jsonObject1.value("amplitude").toInt())%1000));
    sP = QString::number(jsonObject1.value("setPoint").toInt() - ((jsonObject1.value("setPoint").toInt())%1000));
    sC = QString::number(jsonObject1.value("stopCycle").toInt());
    modAmp = QString::number(jsonObject1.value("amplitude").toDouble()/1000);
    modSp = QString::number(jsonObject1.value("setPoint").toDouble()/1000);
    en = true;
    QPair<QString, QString> dateTime = getCurrentDateAndTime();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    excFilePath = jsonObject1.value("excelFilePath").toString() + "/" + currentDateTime.date().toString("yyyy-MM-dd") + " , "+currentDateTime.time().toString("hh-mm") + ".xlsx";//getBatchString(jsonObject1.value("excX").toInt()) +// ".xlsx";
    //excSaveFlag = operation.excelSaveFlg;
    qDebug()<<jsonObject1.value("excX");
    qDebug()<<"sN : "<<sN;
    qDebug()<<"frq : "<<frq;
    qDebug()<<"amp : "<<modAmp;
    qDebug()<<"sP : "<<modSp;
    qDebug()<<"sC : "<<sC;
    qDebug()<<"excel name : "<<excFilePath;
    x = 0;
    f_x = 0;
    columnCount = 0;

    if(!isItemInComboBox(sN)){
        qDebug()<<"insert triggered";
        ui->comboBox_existingParamSelec->addItem(sN);
    }
    comboFlg = true;
    /*if (!xlsx.load()) {
        qDebug() << "Failed to load Excel file:";
        return;
    }*/
    parametersConfig = true;
    chart->axisX()->setRange(x, x+5);
    ser->clear();
}


void MainWindow::on_pushButton_parameters_clicked()
{
    //comboFlg = false;
    int test = jsonManager.getSampleWithHighestIndex();
    qDebug()<<test;
    opFlg = true;
    ec = new elementsContainer(this);
    ec->setAttribute(Qt::WA_DeleteOnClose);
    connect(ec, &elementsContainer::saveData, this, &MainWindow::updateRecentOperations);
    ec->show();
    connect(ec, &elementsContainer::dataAvailable, this, &MainWindow::parameters);
}

void MainWindow::updateRecentOperations() {
    // Add the new operation to the list
    //operations.append(operation);
    //excFilePath = ;
    /*excSaveFlag = operation.excelSaveFlg;
    x = 0;
    columnCount = 0;

    if(excSaveFlag){
        QXlsx::Document xlsx(excFilePath);
        if (!xlsx.load()) {
            qDebug() << "Failed to load Excel file:";
            return;
        }
    }

    parametersConfig = true;
    chart->axisX()->setRange(x, x+5);
    ser->clear();*/
}


void MainWindow::on_pushButton_save_clicked()
{

    //serialPort->close();
    excelHandler->saveAndClose();
    QPair<QString, QString> dateTime = getCurrentDateAndTime();
    bool qwe = jsonManager.addParameter(sN, "endTime", dateTime.second);
    bool sdf = jsonManager.addParameter(sN, "endDate", dateTime.first);
    /*if(saveEn && deviceState == START_OPERATION){
        flg = false;
        QString filePath = excFilePath;

        if(excSaveFlag){
            if (xlsx->saveAs(filePath)) {
                QMessageBox::information(nullptr, "Success", "Excel file created successfully!");
                //xlsx.
                //xlsx = xlsxDoc;
                //excelSaveFlg = true;

            } else {
                QMessageBox::critical(nullptr, "Error", "Failed to create Excel file.");
                //excelSaveFlg = false;
            }

        }
        saveEn = false;
    }
    else{
        QMessageBox::critical(nullptr, "Error", "No operation started");
    }*/
}

void MainWindow::excupdate(int x, int y){

}
int MainWindow::findLastNonEmptyRow(QXlsx::Document &xlsxDoc1) {
    int lastRow = 1;
    // Iterate over rows until an empty row is found
    for (int row = 1; row <= xlsxDoc1.dimension().rowCount(); ++row) {
        if (!xlsxDoc1.cellAt(row, 1)) {  // Check if the first column in the row is empty
            break;
        }
        lastRow = row;
    }
    return lastRow;
}

void MainWindow::on_pushButton_clicked()
{
    if(devState == devInitState){
        if(comConfig){

            QString correctPasscode = "897456";  // Define the correct passcode here
            bool accessGranted = requestPasscode(correctPasscode);

            if (accessGranted) {
                QString command;
                QString str1 = "3";
                command = "set mode " + str1 + "\n";
                writeSerial(command);
                cw = new calibrationWin(this, serialComm);
                connect(dataParser, &DataParser::calParsed, cw, &calibrationWin::onCalSet);
                cw->setAttribute(Qt::WA_DeleteOnClose);
                cw->show();
            } else {

            }

        }
        else{
            QMessageBox::warning(this, "Error", "Please select COM port.");
        }
    }
    else{
        QMessageBox::critical(nullptr, "Error", "please stop the current operation");
    }
}

void MainWindow::updateComPorts(){
    ui->comboBox_comPort->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_comPort->addItem(info.portName());
        //initializeSerialPort(info.portName());
    }

}

void MainWindow::onComboBoxIndexChanged(int index){
    //if (index == -1) return;

}

// Function to monitor the connection status
void MainWindow::monitorConnection()
{
    //QString portName = serialPort->portName();

    // Check if the port is still listed among available ports

}

void MainWindow::updateTimeLapse() {
    if(timeOutNum < sc){
    }else{
        connectionMonitorTimer->stop();
        //startFlg = false;
    }
    elapsedTime++;

    int hours = elapsedTime / 3600;
    int minutes = (elapsedTime % 3600) / 60;
    int seconds = elapsedTime % 60;

    QString timeString = QString::asprintf("%02d:%02d:%02d", hours, minutes, seconds);
    ui->label_timeLapse->setText(timeString);
}

void MainWindow::startTimer(){
    elapsedTime = 1;
    if (!connectionMonitorTimer->isActive()) {
        connectionMonitorTimer->start(1000); // Update every second
    }
}

void MainWindow::on_comboBox_mode_currentIndexChanged1(int index)
{
    if(index == 0){
        if(devState == devManualMode){
            //qDebug()<<portName;
            //serialInit(portName);
            QString command;
            QString str1 = "1";
            command = "set automatic " + str1 + "\n";
            sc = str1.toInt();
            mode = false;
            writeSerial(command);
            //serialNew->writeToSerial(command);
            ui->pushButton_up->setEnabled(false);
            ui->pushButton_down->setEnabled(false);
            //serialPort->close();
            flg = false;
        }
    }
    else{//manual mode
        if(devState == devInitState){
            qDebug()<<portName;
            //serialInit(portName);
            QString command;
            QString str1 = "6";
            command = "set manual " + str1 + "\n";
            sc = str1.toInt();
            mode = true;
            writeSerial(command);
            //serialNew->writeToSerial(command);
            ui->pushButton_up->setEnabled(true);
            ui->pushButton_down->setEnabled(true);
            //serialPort->close();
        }
        else{
            QMessageBox::warning(nullptr, "Input Error", "please stop the existing operation");
        }
    }
}

void MainWindow::on_pushButton_up_clicked()
{
    /* if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "1";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    } */
}


void MainWindow::on_pushButton_down_clicked()
{
    /* if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "0";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    } */
}

void MainWindow::initializeSerialPort(const QString port)
{
    QString portName = port;
    bool success = serialComm->initializeSerialPort(portName, QSerialPort::Baud115200);

    if (!success) {
        QMessageBox::critical(this, "Error", "Failed to open serial port.");
    } else {
        qDebug()<<"connected";
    }
}

void MainWindow::onSerialDataReceived(const QString &data1)
{
    // Read the available data
    readProcess(data1);
}

void MainWindow::onSerialPortError(const QString &error)
{
    QMessageBox::critical(this, "Serial Port Error", error);
}

void MainWindow::writeSerial(const QString data1){
    QString data = data1;
    if (!serialComm->writeToSerial(data)) {
        QMessageBox::warning(this, "Error", "Failed to send data.");
    } else {
    }
}

void MainWindow::on_pushButton_comConnect_clicked()
{
    if (!portFlg)
    {
        serialComm->closeSerialPort();
        ui->pushButton_comConnect->setText(tr("Connect"));
        ui->label_portStatus->setText("inActive");
        ui->label_portStatus->setStyleSheet("color : red");
        //deviceState &= ~COM_CONFIG;
        comConfig = false;
        QMessageBox::warning(this, "Error","Disconnected from serial port.");
        portFlg = true;
        return;
    }
    QString configFilePath = "config.json";
    readComFromJson(configFilePath);
    QString selectedPort = comPortName;//ui->comboBox_comPort->currentText();
    if (selectedPort.isEmpty())
    {
        QMessageBox::warning(this, tr("Error"), tr("No serial port selected!"));
        return;
    }

    initializeSerialPort(selectedPort);

    if (portFlg)
    {
        ui->pushButton_comConnect->setText(tr("Disconnect"));
        ui->label_portStatus->setText("Active");
        //deviceState |= COM_CONFIG;
        comConfig = true;
        QThread::sleep(1);
        readJsonConfig(configFilePath);
        ui->label_portStatus->setStyleSheet("color : green");
        QMessageBox::information(this, "Error","Connected to " + selectedPort);
        portFlg = false;
    }
    else
    {
    }
}

void MainWindow::errorMessage(int state){
    if((state & COM_CONFIG) != COM_CONFIG){
        QMessageBox::warning(nullptr, "Input Error", "Please select the com port");
    }
    if((state & PARAMETERS_CONFIG) != PARAMETERS_CONFIG){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the parameters");
    }
    if((state & START_OPERATION) != START_OPERATION){
        QMessageBox::warning(nullptr, "Input Error", "Please start the operation");
    }
    if((state & STOP_OPERATION) != STOP_OPERATION){
        QMessageBox::warning(nullptr, "Input Error", "No running operations");
    }
    if((state & SAVE_OPERATION) != SAVE_OPERATION){
        QMessageBox::warning(nullptr, "Input Error", "Cannot save while running please stop the operation and click on save");
    }
}

void MainWindow::readJsonConfig(const QString &filePath) {
    // Read the JSON configuration file
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Input Error", "Please calibrate the scale");
        return;
    }

    // Read all the content from the file
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    // Parse the JSON document
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qWarning("Failed to parse the file as a JSON document.");
        return;
    }

    // Extract the JSON object
    QJsonObject configObject = jsonDoc.object();

    // Print the contents to the console
    qDebug() << "Configuration Settings:";
    qDebug() << "App Name:" << configObject["calibration"].toDouble();
    qDebug() << "com port: " << configObject["comPort"].toString();
    QJsonObject databaseConfig = configObject["database"].toObject();
    qDebug() << "Database Username:" << databaseConfig["username"].toString();
    qDebug() << "Database Password:" << databaseConfig["password"].toString();
    comPortName = configObject["comPort"].toString();
    QString command;
    QString str1 = "1";
    command = "set scale " + str1 + "\n";
    //writeSerial(command);
    str1 = QString::number(configObject["calibration"].toDouble());
    command = "calibrate manually " + str1 + "\n";
    writeSerial(command);
    //return configObject["calibration"].toString();
}

void MainWindow::readComFromJson(const QString &filePath) {
    // Read the JSON configuration file
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Input Error", "Please calibrate the scale");
        return;
    }

    // Read all the content from the file
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    // Parse the JSON document
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qWarning("Failed to parse the file as a JSON document.");
        return;
    }

    // Extract the JSON object
    QJsonObject configObject = jsonDoc.object();

    // Print the contents to the console
    qDebug() << "Configuration Settings:";
    qDebug() << "com port: " << configObject["comPort"].toString();
    comPortName = configObject["comPort"].toString();
}

void MainWindow::on_pushButton_up_pressed()
{
    if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "1";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    }
}


void MainWindow::on_pushButton_up_released()
{
    if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "2";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    }
}


void MainWindow::on_pushButton_down_pressed()
{
    if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "3";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    }
}


void MainWindow::on_pushButton_down_released()
{
    if(mode){
        //serialInit(portName);
        QString command;
        QString str1 = "4";
        command = "set manual " + str1 + "\n";
        writeSerial(command);
        //serialNew->writeToSerial(command);
        //serialPort->close();
    }
}


// Function to update the excX value for a given sampleName
void MainWindow::updateExcXInJson(const QString &filePath, const QString &sampleName, double newExcX) {
    QFile jsonFile(filePath);

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file for reading.";
        return;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    if (!jsonDoc.isArray()) {
        qWarning() << "Invalid JSON format: expected an array of operations.";
        return;
    }

    QJsonArray operationArray = jsonDoc.array();
    bool found = false;

    // Iterate through all operations in the array to find the specific sampleName
    for (int i = 0; i < operationArray.size(); ++i) {
        QJsonObject operationObject = operationArray[i].toObject();
        QString existingSampleName = operationObject["sampleName"].toString();

        if (existingSampleName == sampleName) {
            // Update the excX value
            operationObject["excX"] = newExcX;
            operationArray[i] = operationObject; // Update the array with the modified object
            found = true;
            qDebug() << "excX updated for sample:" << sampleName;
            break;
        }
    }

    if (!found) {
        qDebug() << "Sample Name" << sampleName << "not found in the JSON file.";
        return;
    }

    // Write the modified JSON array back to the file
    QJsonDocument updatedDoc(operationArray);
    if (jsonFile.open(QIODevice::WriteOnly)) {
        jsonFile.write(updatedDoc.toJson());
        jsonFile.close();
        qDebug() << "JSON file updated successfully.";
    } else {
        qWarning() << "Couldn't open file for writing.";
    }
}
void MainWindow::getExcXInJson(const QString &filePath, const QString &sampleName, int newExcX){
    QFile jsonFile(filePath);

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file for reading.";
        return;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    if (!jsonDoc.isArray()) {
        qWarning() << "Invalid JSON format: expected an array of operations.";
        return;
    }

    QJsonArray operationArray = jsonDoc.array();
    bool found = false;

    // Iterate through all operations in the array to find the specific sampleName
    for (int i = 0; i < operationArray.size(); ++i) {
        QJsonObject operationObject = operationArray[i].toObject();
        QString existingSampleName = operationObject["sampleName"].toString();

        if (existingSampleName == sampleName) {
            //get the x
            found = true;
            if(excUpdateFlg){
                x = operationObject["excX"].toInt();
            }
            break;
        }
    }

    if (!found) {
        qDebug() << "Sample Name" << sampleName << "not found in the JSON file.";
        return;
    }

    // Write the modified JSON array back to the file
    QJsonDocument updatedDoc(operationArray);
    if (jsonFile.open(QIODevice::WriteOnly)) {
        jsonFile.write(updatedDoc.toJson());
        jsonFile.close();
        qDebug() << "JSON file updated successfully.";
    } else {
        qWarning() << "Couldn't open file for writing.";
    }
}

void MainWindow::loadLabelUp(){
    torqueFlg = true;
}
void MainWindow::readProcess(QString data1){
    //parseData(data1);
    if(caseCount >= 4){
        QString str1 = "1";
        QString command = "set mode " + str1 + "\n";
        writeSerial(command);
        caseCount = 0;
    }
    //qDebug()<<data1; //-ne
    QString data = data1;
    if (data.startsWith("CC")) {
        // Remove the prefix "CC " and the suffix "\r\n"
        data.remove("CC ").remove("\r\n");  // This will remove "CC " wherever it occurs
        int a = data.indexOf("CC");
        data.mid(a,a+2).trimmed();
        // Convert to an integer
        int number = data.toInt();
        ui->lineEdit_currentCycle->setText(data);  // Display the string in the lineEdit
        //qDebug() << "CC " << number;               // Debug print of the number - ne
        timeOutNum = number;
        if (number == sc) {
            startFlg = false;
        }
        saveEn = true;
    }
    if (data.startsWith("mode")) {

        // Remove the prefix "CC " and the suffix "\r\n"
        //data.remove("mode0 : ").remove("\r\n");  // This will remove "CC " wherever it occurs

        //qDebug() <<"data "<< data;
        // Convert to an integer
        //int number = data.toInt();
        //qDebug() << "mode " << devState;               // Debug print of the number - ne
        //devState = number;
        if(data.startsWith("mode0")){
            devState = 0;
        }
        if(data.startsWith("mode1")){
            devState = 1;
        }
        if(data.startsWith("mode2")){
            devState = 2;
        }
        if(data.startsWith("mode3")){
            devState = 3;
        }
        if(data.startsWith("mode4")){
            devState = 4;
        }
    }
    /* if (data.startsWith("receive ")) {
        // Remove the prefix "CC " and the suffix "\r\n"
        qDebug() << data;
        data.remove("received ").remove("\r\n");  // This will remove "CC " wherever it occurs
        if(data.startsWith("frq ")){
            data.remove("frq ");
            if(data.compare(frq) != 0){
                caseCount++;
            }
        }
        if(data.startsWith("sc ")){
            data.remove("sc ");
            if(data.compare(sC) != 0){
                caseCount++;
            }
        }
        if(data.startsWith("amp ")){
            data.remove("amp ");
            if(data.compare(amp) != 0){
                caseCount++;
            }
        }
        if(data.startsWith("sp ") != 0){
            data.remove("sp ");
            if(data.compare(sP)){
                caseCount++;
            }
        }
    }*/
    if (data.startsWith("mode1") && (devState == devStartState)) {
        // Assuming the data received is a number in string format
        bool ok;
        data.remove("mode1 : ").remove("\r\n");
        double yValue = data.toDouble(&ok);        // Convert string to double

        if (ok) {                                  // Proceed if conversion was successful
            double y = yValue;
            //qDebug()<<yValue;// - ne
            int ya = static_cast<int>(y);          // Cast to int
            globalY = ya;
            //sc = 2;
            if (number < 2) {
                if((ya < (amp.toInt() + sP.toInt() + 1000)) && (ya > (amp.toInt() - sP.toInt() - 1000))){
                    //qDebug() << x << " ," << yValue;   // Print values for debugging - ne
                    excelWrite(x, ya);
                    ser->append(x, y);
                    preV = ya;
                }
                else{
                    //qDebug() << x << " ," << yValue;   // Print values for debugging - ne
                    excelWrite(x, preV);
                    ser->append(x, preV);
                }
                //qDebug() << x << " ," << yValue;   // Print values for debugging
                //excelWrite(x, ya);                 // Write to excel
                x += 1;
                if (torqueFlg) {
                    ui->label_Torque->setText(QString::number(globalY));
                    torqueFlg = false;
                }

                if (!connectionMonitorTimer->isActive()) {
                    connectionMonitorTimer->start(1000); // Update every second
                }
            } else {
                connectionMonitorTimer->stop();
                //serialPort->close();
            }

            // Append the data to the series for plotting
            //ser->append(x, y);

            // Adjust the chart range every 500 points
            if (x % 500 == 0) {
                chart->axisX()->setRange(x, x + 500);
                ser->removePoints(0, ser->count() - 500); // Remove points beyond the 500 range
            }
        }
    }
    else if(data.startsWith("mode0")){
        bool ok;
        data.remove("mode0 : ").remove("\r\n");
        double yValue = data.toDouble(&ok);        // Convert string to double

        if (ok) {                                  // Proceed if conversion was successful
            double y = yValue;
            //qDebug()<<yValue; // - ne
            int ya = static_cast<int>(y);          // Cast to int
            globalY = ya;
            if (torqueFlg) {
                ui->label_Torque->setText(QString::number(globalY));
                torqueFlg = false;
            }
        }
    }
    else if(data.startsWith("mode3")){
        bool ok;
        data.remove("mode3 : ").remove("\r\n");
        double yValue = data.toDouble(&ok);        // Convert string to double

        if (ok) {                                  // Proceed if conversion was successful
            double y = yValue;
            //qDebug()<<yValue;  // - ne
            int ya = static_cast<int>(y);          // Cast to int
            globalY = ya;
            if (torqueFlg) {
                ui->label_Torque->setText(QString::number(globalY));
                torqueFlg = false;
            }
        }
    }
    else if(data.startsWith("mode4")){
        bool ok;
        data.remove("mode4 : ").remove("\r\n");
        double yValue = data.toDouble(&ok);        // Convert string to double

        if (ok) {                                  // Proceed if conversion was successful
            double y = yValue;
            //qDebug()<<yValue; // - ne
            int ya = static_cast<int>(y);          // Cast to int
            globalY = ya;
            if (torqueFlg) {
                ui->label_Torque->setText(QString::number(globalY));
                torqueFlg = false;
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(comConfig){
        QString str1 = "1";
        QString command = "set tare " + str1 + "\n";
        writeSerial(command);
    }
    else{
        QMessageBox::warning(nullptr, "Input Error", "Please select the com port");
    }
}

void MainWindow::updateLoadValue(int modeNumber, double loadValue){
    qDebug() << "Mode" << modeNumber << "Load Value:" << loadValue << " , "<< f_x;
    devState = modeNumber;
    if(modeNumber == 1){
        int ya = static_cast<int>(loadValue);          // Cast to int
        globalY = ya;
        if(((ya/1000) < ((amp.toInt() + sP.toInt() + 1)/1000)) && ((ya/1000) > ((amp.toInt() - sP.toInt() - 1)/1000))){
            //qDebug() << x << " ," << yValue;   // Print values for debugging - ne
            if(ui->label_setPoint->text().toFloat() < loadValue){
                int l = ui->label_setPoint->text().toFloat()*1000;
                int g = ui->label_amplitude->text().toFloat()*1000;

                int temp = g%1000 + l%1000;
                qDebug()<<g%1000 + l%1000;
                excelWrite(x, loadValue + temp);
                ser->append(f_x, (loadValue+temp)/1000);
                preV = (loadValue + temp)/1000;
                preVx = loadValue + temp;
            }
            else{
                int l = ui->label_setPoint->text().toFloat()*1000;
                int g = ui->label_amplitude->text().toFloat()*1000;
                int temp = g%1000 + l%1000;
                excelWrite(x, loadValue - temp);
                ser->append(f_x, (loadValue-temp)/1000);
                preV = (loadValue - temp)/1000;
                preVx = loadValue - temp;
            }
        }
        else{
            //qDebug() << x << " ," << yValue;   // Print values for debugging - ne
            excelWrite(x, preVx);
            ser->append(f_x, preV);
        }
        ser->append(f_x, loadValue/1000);
        //qDebug() << x << " ," << yValue;   // Print values for debugging
        //excelWrite(x, ya);                 // Write to excel
        x += 1;
        f_x = (float)x/50;
        if (torqueFlg) {
            ui->label_Torque->setText(QString::number(globalY/1000));
            torqueFlg = false;
        }

        if (!connectionMonitorTimer->isActive()) {
            connectionMonitorTimer->start(1000); // Update every second
        }
        if ((int)(f_x*100) % 500 == 0) {
            chart->axisX()->setRange(f_x, f_x + 5);
            ser->removePoints(0, ser->count() - 5); // Remove points beyond the 500 range
        }
    }
    double y = loadValue;
    //qDebug()<<yValue; // - ne
    int ya = static_cast<int>(y);          // Cast to int
    globalY = ya;
    if (torqueFlg) {
        ui->label_Torque->setText(QString::number(loadValue/1000));
        torqueFlg = false;
    }
}

void MainWindow::updateCycleCount(int cycleCount){
    qDebug() << "CC " << cycleCount;
    QString data = QString::number(cycleCount);
    ui->lineEdit_currentCycle->setText(data);  // Display the string in the lineEdit
    timeOutNum = cycleCount;
    if (cycleCount == sc) {
        startFlg = false;
        on_pushButton_save_clicked();
    }
    saveEn = true;
}

QString MainWindow::getBatchString(int number){
    return QString("batch %1").arg(number);
}

void MainWindow::threadFunc(){
    qDebug()<<"this is thread";
}

QPair<QString, QString> MainWindow::getCurrentDateAndTime() {
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Get the date and time separately
    QString dateString = currentDateTime.date().toString("yyyy-MM-dd");
    QString timeString = currentDateTime.time().toString("hh:mm:ss");

    return QPair<QString, QString>(dateString, timeString);
}

bool MainWindow::requestPasscode(const QString &correctPasscode) {
    bool ok;
    QString inputPasscode = QInputDialog::getText(nullptr, "Passcode Required",
                                                  "Enter Passcode:", QLineEdit::Password,
                                                  "", &ok);
    if (ok) {  // ok is true if the user clicked OK, and not Cancel
        if (inputPasscode == correctPasscode) {
            QMessageBox::information(nullptr, "Access Granted", "Passcode is correct!");
            return true;
        } else {
            QMessageBox::warning(nullptr, "Access Denied", "Incorrect passcode.");
            return false;
        }
    }
    return false;  // If the user clicked Cancel
}

WelcomeDialog::WelcomeDialog(const QString &imagePath, QWidget *parent) : QDialog(parent) {
    // Set dialog properties
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);  // Remove window frame
    setAttribute(Qt::WA_TranslucentBackground);  // Set transparent background
    setFixedSize(400, 300);  // Adjust size to match your image dimensions if necessary

    // Set up QLabel to display the image
    QLabel *imageLabel = new QLabel(this);
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imageLabel->setAlignment(Qt::AlignCenter);

    // Set layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    setLayout(layout);

    // Set up timer to close the dialog after 2 seconds
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WelcomeDialog::accept);  // Close dialog after timeout
    timer->start(2000);  // 2000 milliseconds = 2 seconds
}


double MainWindow::updateWave(){
    double ampl = amp.toDouble();
    double setpoint = sP.toDouble();
    double y = ampl + (setpoint * std::sin(2 * M_PI * frq.toInt() * f_x));
    return y;
}

void MainWindow::on_comboBox_existingParamSelec_currentTextChanged(const QString &arg1)
{

}

void MainWindow::loadComboBox(){
    // Get samples sorted by ascending index
    QList<QJsonObject> sortedSamples = listSamplesByAscendingIndex(jsonManager);
    for (const QJsonObject& sample : sortedSamples) {
        QString sampleName = sample.value("sampleName").toString();
        int index = sample.value("index").toInt();
        qDebug() << "Sample Name:" << sampleName << "Index:" << index;
        // ui->recentOperationsListWidget->addItem(sampleName);
        ui->comboBox_existingParamSelec->addItem(sampleName, index);

    }
    // populateComboBoxWithExcelFiles("E:/excelTest/sampleEsp");
}

// Function to list sample parameters by ascending index
QList<QJsonObject> MainWindow::listSamplesByAscendingIndex(JsonManager& jsonManager4) {
    // Retrieve all samples from JsonManager
    QJsonArray samplesArray = jsonManager4.getAllSamples();

    // Convert QJsonArray to QList<QJsonObject> for easier sorting
    QList<QJsonObject> samplesList;
    for (const QJsonValue& sampleValue : samplesArray) {
        samplesList.append(sampleValue.toObject());
    }

    // Sort samplesList by the "index" field in ascending order
    std::sort(samplesList.begin(), samplesList.end(), [](const QJsonObject& a, const QJsonObject& b) {
        return a.value("index").toInt() < b.value("index").toInt();
    });


    return samplesList;
}


void MainWindow::on_comboBox_existingParamSelec_currentIndexChanged(int index)
{
    qDebug()<<index;
    x = 0;
    QJsonObject samples = jsonManager.loadParametersByIndex(index);

    if(!samples.empty()){
        int tempX = samples.value("excX").toInt();
        QString tempStr = samples.value("sampleName").toString();
        jsonManager.updateParameter(tempStr, "excX", tempX + 1);
    }
    parameters(index);
    comboFlg = true;
}

