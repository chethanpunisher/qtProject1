#include "calibrationwin.h"
#include "ui_calibrationwin.h"

calibrationWin::calibrationWin(QWidget *parent,SerialComm* sp)
    : QDialog(parent)
    , ui(new Ui::calibrationWin)
{
    ui->setupUi(this);
    serial = sp;
    connect(serial, &SerialComm::dataReceived, this, &calibrationWin::readSerial);
}

calibrationWin::~calibrationWin()
{
    delete ui;
}

void calibrationWin::on_pushButton_clicked()
{
    QMessageBox::StandardButton ins1;
    ins1 = QMessageBox::question(this, "calibration", "Remove weight on the scale",
                                  QMessageBox::Yes | QMessageBox::No);
    if(ins1){
        qDebug() << "Serial port opened successfully.";

        // Transmit the "hi" string
        QString str1;
        QString command;
        str1 = "1";
        command = "set scale " + str1 + "\n";
        //writeSerial(command);

        // Ensure all data is written before closing the port
        if (serial->writeToSerial(command)) {
            qDebug() << "Message sent: " << command;
            QMessageBox::information(nullptr, "Success", "Calibration sent successfully!");
        } else {
            qDebug() << "Failed to send message.";
        }
    }

    QMessageBox::StandardButton ins2;
    ins2 = QMessageBox::question(this, "calibration", "Now place the reference weight on the scale",
                                  QMessageBox::Yes | QMessageBox::No);

    if(ins1 && ins2){
        qDebug() << "Serial port opened successfully.";

        // Transmit the "hi" string
        QString str1;
        QString command;
        str1 = ui->lineEdit_calibrationIput->text();
        command = "set calibration " + str1 + "\n";
        //writeSerial(command);

        // Ensure all data is written before closing the port
        if (serial->writeToSerial(command)) {
            qDebug() << "Message sent: " << command;
            //QString cali = serial->readFromSerial();
            //qDebug()<<cali;
            QMessageBox::information(nullptr, "Success", "Calibration sent successfully!");

            //QString configFilePath = "config.json";
            //generateJsonConfig();
        } else {
            qDebug() << "Failed to send message.";
        }
        str1;
        command;
        str1 = "0";
        command = "set mode " + str1 + "\n";
        if (serial->writeToSerial(command)) {

        } else {
            qDebug() << "Failed to send message.";
        }
    }
}

void calibrationWin::writeSerial(const QString data1){
    QString data = data1;
    if (!serial->writeToSerial(data)) {
        QMessageBox::warning(this, "Error", "Failed to send data.");
    } else {
    }
}

void calibrationWin::generateJsonConfig(const QString &filePath, const QString &calibrationVal) {
    // Create a JSON object to store the configuration
    QJsonObject configObject;

    // Add basic configuration settings
    configObject["calibration"] = calibrationVal;

    // Add additional settings in nested objects
    QJsonObject databaseConfig;
    databaseConfig["username"] = "pieIndia";
    databaseConfig["password"] = "pie@1234";
    configObject["database"] = databaseConfig;

    // Write to JSON file
    QJsonDocument jsonDoc(configObject);
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file for writing.");
        return;
    }

    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
    qDebug() << "Configuration file created successfully!";
}


void calibrationWin::on_pushButton_2_clicked()
{
    QString str1;
    QString command;
    str1 = ui->lineEdit_manualCalibration->text();
    command = "calibrate manually " + str1 + "\n";

    if (serial->writeToSerial(command)) {
        qDebug() << "Message sent: " << command;
        //QString cali = serial->readFromSerial();
        //qDebug()<<cali;
        QMessageBox::information(nullptr, "Success", "Calibration sent successfully!");

        //QString configFilePath = "config.json";
        //generateJsonConfig();
    } else {
        qDebug() << "Failed to send message.";
    }
}

void calibrationWin::readSerial(const QString &caliVal){
    /*QString temp = caliVal;
    QString calData = temp.remove("\r\n");
    QString configFilePath = "config.json";
    generateJsonConfig(configFilePath, calData);*/
    QString data1 = caliVal;
    if(data1.startsWith("calibrate")){
        bool ok;
        data1.remove("calibrate ").remove("\r\n");
        QString configFilePath = "config.json";
        generateJsonConfig(configFilePath, data1);
    }
}


void calibrationWin::on_calibrationDownButton_pressed()
{
    QString command;
    QString str1 = "6";
    command = "set manual " + str1 + "\n";
    writeSerial(command);

    str1 = "3";
    command = "set manual " + str1 + "\n";
    writeSerial(command);
}


void calibrationWin::on_calibrationDownButton_released()
{
    QString command;
    QString str1;
    str1 = "4";
    command = "set manual " + str1 + "\n";
    writeSerial(command);

    str1 = "3";
    command = "set mode " + str1 + "\n";
    writeSerial(command);
}


void calibrationWin::on_calibrationUpButton_pressed()
{
    QString command;
    QString str1 = "6";
    command = "set manual " + str1 + "\n";
    writeSerial(command);

    str1 = "1";
    command = "set manual " + str1 + "\n";
    writeSerial(command);
}


void calibrationWin::on_calibrationUpButton_released()
{
    QString command;
    QString str1;

    str1 = "2";
    command = "set manual " + str1 + "\n";
    writeSerial(command);

    str1 = "3";
    command = "set mode " + str1 + "\n";
    writeSerial(command);
}

