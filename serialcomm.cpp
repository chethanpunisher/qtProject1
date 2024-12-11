#include "SerialComm.h"
#include <QDebug>
#include <QThread>

SerialComm::SerialComm(QObject *parent) : QObject(parent), serialPort(new QSerialPort(this))
{
    connect(serialPort, &QSerialPort::readyRead, this, &SerialComm::handleReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &SerialComm::handleError);
}

SerialComm::~SerialComm()
{
    closeSerialPort();
}

bool SerialComm::initializeSerialPort(const QString &portName, int baudRate)
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    bool portFound = false;
    for (const QSerialPortInfo &portInfo : availablePorts) {
        if (portInfo.portName() == portName) {
            portFound = true;
            break;
        }
    }

    if (!portFound) {
        qDebug() << "Port not found:" << portName;
        emit errorOccurred("Port not found: " + portName);
        return false;
    }

    serialPort->setPortName(portName);
    if (!serialPort->setBaudRate(baudRate)) {
        qDebug() << "Invalid baud rate:" << baudRate;
        emit errorOccurred("Invalid baud rate");
        return false;
    }

    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open port" << portName << "with error:" << serialPort->errorString();
        emit errorOccurred(serialPort->errorString());
        return false;
    }
    serialPort->setRequestToSend(true);

    serialPort->setDataTerminalReady(true);
    QThread::msleep(100);

    //connect(serialPort, &QSerialPort::errorOccurred, this, &SerialComm::handleSerialError);
    return true;
}

void SerialComm::closeSerialPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

bool SerialComm::writeToSerial(const QString &data)
{
    if (serialPort->isOpen() && !data.isEmpty()) {
        serialPort->write(data.toUtf8());
        return true;
    }
    emit errorOccurred(tr("Serial port is not open or data is empty."));
    return false;
}

QString SerialComm::readFromSerial()
{
    if (serialPort->isOpen()) {
        return QString(serialPort->readAll());
    }
    emit errorOccurred(tr("Serial port is not open."));
    return QString();
}

QStringList SerialComm::getAvailablePorts() const
{
    QStringList portList;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        portList << info.portName();
    }
    return portList;
}

bool SerialComm::isPortOpen() const
{
    return serialPort->isOpen();
}

void SerialComm::handleReadyRead()
{
    const QByteArray data = serialPort->readAll();
    emit dataReceived(QString(data));
}

void SerialComm::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        emit errorOccurred(serialPort->errorString());
    }
}
