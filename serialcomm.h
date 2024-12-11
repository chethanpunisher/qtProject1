#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialComm : public QObject
{
    Q_OBJECT

public:
    explicit SerialComm(QObject *parent = nullptr);
    ~SerialComm();

    bool initializeSerialPort(const QString &portName, int baudRate = QSerialPort::Baud9600);
    void closeSerialPort();
    bool writeToSerial(const QString &data);
    QString readFromSerial();
    QStringList getAvailablePorts() const;
    bool isPortOpen() const;

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &error);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *serialPort;
};

#endif // SERIALCOMM_H
