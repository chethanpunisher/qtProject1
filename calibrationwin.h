#ifndef CALIBRATIONWIN_H
#define CALIBRATIONWIN_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include "serialcomm.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>

namespace Ui {
class calibrationWin;
}

class calibrationWin : public QDialog
{
    Q_OBJECT

public:
    explicit calibrationWin(QWidget *parent = nullptr, SerialComm* sp = nullptr);
    ~calibrationWin();

private slots:

    void on_pushButton_2_clicked();

    void on_calibrationDownButton_pressed();

    void on_calibrationDownButton_released();

    void on_calibrationUpButton_pressed();

    void on_calibrationUpButton_released();


    void on_pushButton_calibrate_clicked();

public slots:
    void onCalSet(double calVal);


private:
    Ui::calibrationWin *ui;
    SerialComm *serial;
    void writeSerial(const QString data1);
    void generateJsonConfig(const QString &filePath, const double &calibrationVal);
    void readSerial(const QString &caliVal);
};

#endif // CALIBRATIONWIN_H
