#include "elementscontainer.h"
#include "ui_elementscontainer.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QtAlgorithms>
#include "jsonmanager.h"
#include <QStringListModel>

QString jsonFilePath1 = "sampleData.json";
JsonManager jsonManager1(jsonFilePath1);

elementsContainer::elementsContainer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::elementsContainer)
{



    existingSel = false;
    jsonManager1.createJsonFile();
    excelSaveFlg = false;
    excelUpdateFlg = false;
    paramSetFlg = false;
    selIndex = -1;
    x = 0;
    columnCount = 0;
    ui->setupUi(this);
    //completer->setCaseSensitivity(Qt::CaseInsensitive);

    displayRecentOperations();

    connect(ui->recentOperationsListWidget, &QListWidget::itemClicked, this, &elementsContainer::onRecentOperationClicked);
    connect(this, &elementsContainer::finished, this, [this](){
        if(selIndex != -1){
            emit dataAvailable(selIndex);
        }
        //emit dataAvailable(ui->lineEdit_sampleName->text(), ui->lineEdit_frequency->text(), ui->lineEdit_setPoint->text(), ui->lineEdit_amplitude->text(), ui->lineEdit_stopCycle->text(),completer);
    });
}




elementsContainer::~elementsContainer()
{
    delete ui;
}

void elementsContainer::on_pushButton_Set_clicked()
{
    en = true;
    if(ui->lineEdit_sampleName->text().isEmpty()){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the sample name.");
        en = false;
    }

    if(ui->lineEdit_frequency->text().isEmpty()){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the frequency.");
        en = false;
    }

    if(ui->lineEdit_amplitude->text().isEmpty()){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the amplitude.");
        en = false;
    }

    if(ui->lineEdit_setPoint->text().isEmpty()){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the set point.");
        en = false;
    }

    if(ui->lineEdit_stopCycle->text().isEmpty()){
        QMessageBox::warning(nullptr, "Input Error", "Please enter the stop cycle.");
        en = false;
    }

    if(en){
        //dialogOpen();
        saveExcel();
        // Create a new operation object from the input fields
        QJsonObject newSampleParams;

        if(existingSel){
            selIndex = In;
        }
        else{
            newSampleParams["sampleName"] = ui->lineEdit_sampleName->text();
            newSampleParams["frequency"] = ui->lineEdit_frequency->text().toInt();
            newSampleParams["stopCycle"] = ui->lineEdit_stopCycle->text().toInt();
            newSampleParams["amplitude"] = ((int)(ui->lineEdit_setPoint->text().toFloat()*1000));
            newSampleParams["setPoint"] = ((int)(ui->lineEdit_amplitude->text().toFloat()*1000));
            newSampleParams["excelFilePath"] = excelFilePath;
            newSampleParams["excelSaveFlg"] = excelSaveFlg;
            newSampleParams["excelUpdateFlg"] = excelUpdateFlg;
            In = jsonManager1.getSampleWithHighestIndex();
            selIndex = In+1;
            qDebug()<<In;
            newSampleParams["excX"] = x;
            newSampleParams["index"] = In+1;
            newSampleParams["columnCount"] = columnCount;
            jsonManager1.addOperationParameters(newSampleParams);
        }
        bool suc = jsonManager1.updateParameter(ui->lineEdit_sampleName->text(), "excX", x);
        qDebug()<<"x success: "<<suc;
        // Emit the data to the MainWindow
        qDebug()<<"excel flag"<<excelUpdateFlg;
        qDebug()<<"selIdex"<<selIndex;
        emit saveData();
        //performSearch();

        close();
    }
}


void elementsContainer::on_pushButton_clear_clicked()
{
    performSearch();
    ui->lineEdit_sampleName->clear();
    ui->lineEdit_amplitude->clear();
    ui->lineEdit_frequency->clear();
    ui->lineEdit_setPoint->clear();
    ui->lineEdit_stopCycle->clear();
    excelSaveFlg = false;
    excelUpdateFlg = false;
    selIndex = -1;
    x = 0;
    existingSel = false;
}

void elementsContainer::performSearch() {
    QString searchTerm = ui->lineEdit_sampleName->text();

    // Add search term to recent searches if not already present
    if (!recentSearches.contains(searchTerm)) {
        recentSearches.append(searchTerm);
        completer->setModel(new QStringListModel(recentSearches, completer));
    }
    // Update result label
    //resultLabel->setText("Searching for: " + searchTerm);
}

// Slot to handle clicks on recent operations
void elementsContainer::onRecentOperationClicked(QListWidgetItem *item) {
    // Get the index of the clicked item

    int index = ui->recentOperationsListWidget->row(item);
    qDebug()<<index;


    QJsonObject samples = jsonManager1.loadParametersByIndex(index);

    if(!samples.empty()){
        ui->lineEdit_sampleName->setText(samples.value("sampleName").toString());
        qDebug()<< samples.value("stopCycle");
        ui->lineEdit_frequency->setText(QString::number(samples.value("frequency").toDouble()));
        ui->lineEdit_stopCycle->setText(QString::number(samples.value("stopCycle").toDouble()));
        ui->lineEdit_setPoint->setText(QString::number(samples.value("amplitude").toDouble()/1000));
        ui->lineEdit_amplitude->setText(QString::number(samples.value("setPoint").toDouble()/1000));
        excelFilePath = samples.value("excelFilePath").toString();
        excelSaveFlg = samples.value("excelSaveFlg").toBool();
        selIndex = index;
        x = samples.value("excX").toInt();
        In = samples.value("index").toInt();
        existingSel = true;
    }
}

void elementsContainer::displayRecentOperations() {
    ui->recentOperationsListWidget->clear(); // Clear existing items

    // Get samples sorted by ascending index
    QList<QJsonObject> sortedSamples = listSamplesByAscendingIndex(jsonManager1);
    for (const QJsonObject& sample : sortedSamples) {
        QString sampleName = sample.value("sampleName").toString();
        int index = sample.value("index").toInt();
        qDebug() << "Sample Name:" << sampleName << "Index:" << index;
        ui->recentOperationsListWidget->addItem(sampleName);
    }
}

void elementsContainer::saveExcel(){
    // Create a pop-up dialog for selecting the save location
    //x = 0;

    //excelFilePath = directory;

    if (!excelSaveFlg) {

        excelFilePath = FolderCreation();
        QString filePath = excelFilePath + "/" + getBatchString(x);

        if (!filePath.endsWith(".xlsx", Qt::CaseInsensitive)) {
            filePath += ".xlsx";
        }
        //excelFilePath = filePath;
        // Save the Excel file to the selected path
        // if (xlsx.saveAs(filePath)) {
        //     QMessageBox::information(nullptr, "Success", "Excel file created successfully!");
        //     excelSaveFlg = true;
        //     //x = x+1;
        // } else {
        //     QMessageBox::critical(nullptr, "Error", "Failed to create Excel file.");
        //     excelSaveFlg = false;
        // }
    } else {
        x = x+1;
        QString filePath = excelFilePath + "/" + getBatchString(x);

        if (!filePath.endsWith(".xlsx", Qt::CaseInsensitive)) {
            filePath += ".xlsx";
        }
        //excelFilePath = filePath;

        // Save the Excel file to the selected path
        // if (xlsx.saveAs(filePath)) {
        //     QMessageBox::information(nullptr, "Success", "Excel file created successfully!");
        // } else {
        //     QMessageBox::critical(nullptr, "Error", "Failed to create Excel file.");
        // }
    }
}

void elementsContainer::dialogOpen(){
    // Ask the user if they want to save the file
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Excel File", "Do you want to save this file?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // If the user confirms, save the file

        if(excelSaveFlg){
            excelUpdateFlg = true;
        }
        else{
            saveExcel();
        }
        excelSaveFlg = true;

    } else {
        excelSaveFlg = false;
        // If the user chooses not to save
        //QMessageBox::information(this, "Cancelled", "File save operation cancelled.");
    }
}

QString elementsContainer::FolderCreation(){
    // Open a QFileDialog to select or create a folder path
    QString folderPath1 = QFileDialog::getExistingDirectory(nullptr, "Select or Create Folder",
                                                            QDir::homePath(),
                                                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString name = ui->lineEdit_sampleName->text();
    QString folderPath = folderPath1 + "/" + name;
    // Check if the user selected a valid path
    if (folderPath.isEmpty()) {
        qDebug() << "No folder selected.";
        return QString(); // Return an empty string if no folder was selected
    }

    // Check if the folder exists; if not, create it
    QDir dir;
    if (!dir.exists(folderPath)) {
        if (dir.mkpath(folderPath)) {
            qDebug() << "Folder created successfully at:" << folderPath;
        } else {
            qDebug() << "Failed to create folder at:" << folderPath;
            return QString();
        }
    } else {
        qDebug() << "Folder already exists at:" << folderPath;
    }

    // Return the path of the selected or newly created folder
    return folderPath;
}

QString elementsContainer::getBatchString(int number){
    return QString("batch %1").arg(number);
}

// Function to list sample parameters by ascending index
QList<QJsonObject> elementsContainer::listSamplesByAscendingIndex(JsonManager& jsonManager) {
    // Retrieve all samples from JsonManager
    QJsonArray samplesArray = jsonManager.getAllSamples();

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
