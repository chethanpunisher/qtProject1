#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include <QString>

class DataParser : public QObject {
    Q_OBJECT

public:
    explicit DataParser(QObject* parent = nullptr);

signals:
    void loadDataParsed(int modeNumber, double loadValue);  // Signal to send load value along with mode number
    void cycleCountParsed(int cycleCount);                  // Signal to send cycle count

public slots:
    void parseData(const QString& rawData);  // Slot to parse incoming data

private:
    QString buffer;  // Buffer to hold incoming data
    void processMessage(const QString& message);  // Function to process each message
};

#endif // DATAPARSER_H
