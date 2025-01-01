#include "analysisplot.h"
#include "ui_analysisplot.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include <xlsxdocument.h>
#include <limits>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>

// Movement variables


QString jsonFilePath3 = "sampleData.json";
JsonManager jsonManager3(jsonFilePath3);

ExcelLoader2::ExcelLoader2(const QString &filePath, QObject *parent)
    : QObject(parent), filePath(filePath) {}

void ExcelLoader2::load() {
    QXlsx::Document xlsx(filePath);
    QVector<QPointF> data;
    qreal yMin = std::numeric_limits<qreal>::max();
    qreal yMax = std::numeric_limits<qreal>::min();

    qDebug() << filePath;

    int rowLimit = 800000;   // Limit rows per column block
    int currentCol = 1;  // Start at column 1 (A)

    while (true) {
        QString slNoHeader = xlsx.read(1, currentCol).toString();
        QString sampleNameHeader = xlsx.read(1, currentCol + 1).toString();

        if (slNoHeader.isEmpty() || sampleNameHeader.isEmpty()) {
            break;  // End when no more data is found
        }

        qDebug() << "Reading Data from Columns:" << slNoHeader << "and" << sampleNameHeader;

        // Read each row in the block (up to rowLimit)
        for (int row = 2; row <= rowLimit + 1; ++row) {
            QVariant slNoValue = xlsx.read(row, currentCol);
            QVariant sampleNameValue = xlsx.read(row, currentCol + 1);

            if (slNoValue.isNull() && sampleNameValue.isNull()) {
                continue;  // Skip empty rows
            }

            qreal x = slNoValue.toInt() / 50.0;    // Scale down X-axis by 1/50
            qreal y = sampleNameValue.toInt() / 1000.0;  // Scale down Y-axis by 1/1000
            data.append(QPointF(x, y));

            if (y < yMin) yMin = y;
            if (y > yMax) yMax = y;

            emit progressUpdated(row - 1);
            qDebug() << "Sl No:" << slNoValue.toInt() << ", Sample Name:" << sampleNameValue.toString();
        }

        currentCol += 2;  // Move to the next set of columns
    }

    emit dataLoaded(data, yMin, yMax);
    emit finished();
}



AnalysisPlot::AnalysisPlot(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AnalysisPlot),
    chart(new QChart()),
    chartView(new QChartView(chart)),
    series(new QLineSeries()),
    axisX(new QValueAxis()),
    axisY(new QValueAxis()),
    leftButton(new QPushButton("Move Left")),
    rightButton(new QPushButton("Move Right")),
    progressBar(new QProgressBar(this))
{
    ui->setupUi(this);

    // Load the Excel file
    // QString filePath = QFileDialog::getOpenFileName(this,
    //                                                 "Open Excel File",
    //                                                 QDir::homePath(),
    //                                                 "Excel Files (*.xlsx)");
    // let = extractSample(filePath);
    qDebug()<<let;
    resize(800, 600); // Set the initial size of the PlotWindow to 800x600

    setupUI();
    setupChart();
    // if (!filePath.isEmpty()) {
    //     startLoading(filePath);
    // } else {
    //     QMessageBox::warning(this, "Cancelled", "File open operation was cancelled.");
    // }
    loadComboBox();
    // Timer for smooth movement
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &AnalysisPlot::timerUpdate);
    // Movement variables
    direction = 0;       // -1 for left, +1 for right
    speed = 0.1;      // Initial speed
    maxSpeed = 2.0;   // Maximum speed
    acceleration = 0.05;  // Acceleration
}

AnalysisPlot::~AnalysisPlot()
{
    delete ui;
}

void AnalysisPlot::setupChart()
{
    chart->setTitle("LOAD vs TIME");
    chart->addSeries(series);
    chart->createDefaultAxes();

    axisX->setTitleText("Time in Sec");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(6);
    chart->setAxisX(axisX, series);

    axisY->setTitleText("Load in Ton");
    axisY->setLabelFormat("%d");
    //axisY->setTickCount(10);
    //axisY->setRange(0,);
    chart->setAxisY(axisY, series);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
}

void AnalysisPlot::setupUI()
{
    ui->verticalLayout_6->addWidget(chartView);
    QJsonObject sampleDis = jsonManager3.readParameters(let);

    ui->sampleLabel->setText(sampleDis.value("sampleName").toString());
    ui->frequencyLabel->setText(QString::number(sampleDis.value("frequency").toDouble()));
    ui->AmplitudeLabel->setText(QString::number(sampleDis.value("setPoint").toDouble()/1000));
    ui->setPointLabel->setText(QString::number(sampleDis.value("amplitude").toDouble()/1000));
    ui->stopCycleLabel->setText(QString::number(sampleDis.value("stopCycle").toDouble()));
    ui->startTimeLabel->setText(sampleDis.value("startTime").toString());
    ui->stopTimeLabel->setText(sampleDis.value("endTime").toString());
    ui->startDateLabel->setText(sampleDis.value("startDate").toString());
    ui->endDateLabel->setText(sampleDis.value("endDate").toString());
    QString filePathNam = "NamingConfig.json";
    QPair<QString, QString> result = readJsonFile(filePathNam);

    if (!result.first.isEmpty() && !result.second.isEmpty()) {
        qDebug() << "Name:" << result.first;
        qDebug() << "Address:" << result.second;
        ui->NameLabel->setText(result.first);
        ui->AddrLabel->setText(result.second);
    } else {
        qDebug() << "Failed to read JSON data.";
    }
}


void AnalysisPlot::startLoading(const QString &filePath)
{
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setVisible(true);

    // Create a new thread
    QThread *thread = new QThread;
    ExcelLoader2 *loader = new ExcelLoader2(filePath);
    loader->moveToThread(thread);

    // Connect signals and slots
    connect(thread, &QThread::started, loader, &ExcelLoader2::load);
    connect(loader, &ExcelLoader2::progressUpdated, this, &AnalysisPlot::updateProgress);
    connect(loader, &ExcelLoader2::dataLoaded, this, &AnalysisPlot::onDataLoaded);
    connect(loader, &ExcelLoader2::finished, thread, &QThread::quit);
    connect(loader, &ExcelLoader2::finished, loader, &ExcelLoader2::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void AnalysisPlot::loadComboBox(){
    // Get samples sorted by ascending index
    QList<QJsonObject> sortedSamples = listSamplesByAscendingIndex(jsonManager3);
    for (const QJsonObject& sample : sortedSamples) {
        QString sampleName = sample.value("sampleName").toString();
        int index = sample.value("index").toInt();
        qDebug() << "Sample Name:" << sampleName << "Index:" << index;
        // ui->recentOperationsListWidget->addItem(sampleName);
        ui->comboBox_sampleSelec->addItem(sampleName, index);

    }
    // populateComboBoxWithExcelFiles("E:/excelTest/sampleEsp");
}

// Function to list sample parameters by ascending index
QList<QJsonObject> AnalysisPlot::listSamplesByAscendingIndex(JsonManager& jsonManager4) {
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

void AnalysisPlot::populateComboBoxWithExcelFiles(const QString& folderPath) {
    // Set up the directory
    QDir dir(folderPath);

    // Filter for Excel files
    QStringList filters;
    filters << "*.xls" << "*.xlsx";  // Add more extensions if needed
    dir.setNameFilters(filters);

    // Get the list of files
    QStringList excelFiles = dir.entryList(QDir::Files);

    // Clear existing items in the comboBox (optional)
    // comboBox->clear();
    ui->comboBox_batchSelec->clear();

    // Populate the comboBox with file names
    for (const QString& fileName : excelFiles) {
        // comboBox->addItem(fileName);  // Add the file name
        ui->comboBox_batchSelec->addItem(fileName);
    }

    // Debug information
    if (excelFiles.isEmpty()) {
        qWarning() << "No Excel files found in directory:" << folderPath;
    } else {
        qDebug() << "Excel files found:" << excelFiles;
    }
}

void AnalysisPlot::updateProgress(int value)
{
    progressBar->setValue(value);
}

void AnalysisPlot::onDataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax)
{
    series->replace(data);
    axisX->setRange(0, 5);//data.first().x(), data.last().x() - (data.last().x() - 5));
    axisY->setRange(0, yMax);
    qDebug()<<yMin<<", "<<yMax;
    progressBar->setVisible(false);
}

void AnalysisPlot::moveLeft()
{
    qreal step = (axisX->max() - axisX->min()) * 1;
    axisX->setRange(axisX->min() - step, axisX->max() - step);
}

void AnalysisPlot::moveRight()
{
    qreal step = (axisX->max() - axisX->min()) * 1;
    axisX->setRange(axisX->min() + step, axisX->max() + step);
}

QString AnalysisPlot::extractSample(const QString &input) {
    // Define the regular expression to match "sample" followed by any number
    QRegularExpression re(R"(sample[-\w]+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = re.match(input);

    // Check if the regex matched successfully and return the matched text
    if (match.hasMatch()) {
        return match.captured(0); // captured(0) returns the full match, e.g., "sample4"
    }

    // If no match is found, return an empty string or handle as needed
    return QString();
}

void AnalysisPlot::on_moveRightButton_clicked()
{
    // qreal step = (axisX->max() - axisX->min()) * 1;
    // axisX->setRange(axisX->min() + step, axisX->max() + step);
}


void AnalysisPlot::on_moveLeftButton_clicked()
{
    // qreal step = (axisX->max() - axisX->min()) * 1;
    // axisX->setRange(axisX->min() - step, axisX->max() - step);
}

QPair<QString, QString> AnalysisPlot::readJsonFile(const QString &filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open the file:" << filePath;
        return QPair<QString, QString>(); // Return an empty pair on failure
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return QPair<QString, QString>(); // Return an empty pair if JSON is invalid
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString name = jsonObj.value("Name").toString();
    QString address = jsonObj.value("Address").toString();

    return QPair<QString, QString>(name, address);
}

void AnalysisPlot::on_comboBox_sampleSelec_currentTextChanged(const QString &arg1)
{
    qDebug()<<arg1;
    QJsonObject sampleDis = jsonManager3.readParameters(arg1);

    if(1){

        ui->sampleLabel->setText(sampleDis.value("sampleName").toString());
        ui->frequencyLabel->setText(QString::number(sampleDis.value("frequency").toDouble()));
        ui->AmplitudeLabel->setText(QString::number(sampleDis.value("setPoint").toDouble()/1000));
        ui->setPointLabel->setText(QString::number(sampleDis.value("amplitude").toDouble()/1000));
        ui->stopCycleLabel->setText(QString::number(sampleDis.value("stopCycle").toDouble()));
        ui->startTimeLabel->setText(sampleDis.value("startTime").toString());
        ui->stopTimeLabel->setText(sampleDis.value("endTime").toString());
        ui->startDateLabel->setText(sampleDis.value("startDate").toString());
        ui->endDateLabel->setText(sampleDis.value("endDate").toString());

        tempEx = sampleDis.value("excelFilePath").toString();
        qDebug()<<tempEx;
        populateComboBoxWithExcelFiles(tempEx);


    }
}

void AnalysisPlot::on_comboBox_batchSelec_currentTextChanged(const QString &arg1)
{

    QString tempEx2 = tempEx+ "/" +arg1;
    qDebug()<<tempEx2;
    if (!tempEx2.isEmpty()) {
        startLoading(tempEx2);
    } else {
        QMessageBox::warning(this, "Cancelled", "File open operation was cancelled.");
    }
}

void AnalysisPlot::timerUpdate(){
    qDebug()<<"moving";
    if (direction != 0) {

        double start = axisX->min() + direction * speed;
        double end = axisX->max() + direction * speed;
        axisX->setRange(start, end);
    }
    if (speed < maxSpeed) {
        speed += acceleration;  // Increase speed linearly
    }
}



void AnalysisPlot::on_moveLeftButton_pressed()
{
    qDebug()<<"left pressed";
    direction = -1;  // Move left
    speed = 0.1;     // Reset speed
    timer->start(20);  // Start moving (20 ms interval)
}


void AnalysisPlot::on_moveRightButton_pressed()
{
    direction = 1;   // Move right
    speed = 0.1;     // Reset speed
    timer->start(20);  // Start moving (20 ms interval)
}


void AnalysisPlot::on_moveLeftButton_released()
{
    stopMovement();
}


void AnalysisPlot::on_moveRightButton_released()
{
    stopMovement();
}

void AnalysisPlot::stopMovement(){
    timer->stop();
    direction = 0;  // Stop moving
}
