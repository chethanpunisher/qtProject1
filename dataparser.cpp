#include "dataparser.h"
#include <QRegularExpression>
#include <QDebug>

// Constructor
DataParser::DataParser(QObject* parent) : QObject(parent) {}

// Slot to parse incoming data
void DataParser::parseData(const QString& rawData) {
    // Append incoming data to the buffer
    buffer += rawData;

    // Process complete messages based on the delimiter "\r\n"
    int index;
    while ((index = buffer.indexOf("\r\n")) != -1) {
        // Extract the complete message
        QString message = buffer.left(index).trimmed();
        buffer.remove(0, index + 2);  // Remove the processed message from the buffer

        // Process the message
        processMessage(message);
    }
}

// Function to process each individual message
void DataParser::processMessage(const QString& message) {
    // Define regular expressions for each data pattern using QRegularExpression
    QRegularExpression modeRegex("^mode(\\d+) : (-?\\d+(\\.\\d*)?)$");  // Matches "mode<number> : <load>"
    QRegularExpression cycleCountRegex("^CC (\\d+)$");                  // Matches "CC <cycle count>"
    QRegularExpression calSetRegex("^CalSet : (-?\\d+(\\.\\d*)?)$");

    QRegularExpressionMatch match;

    // Match against mode<number> : <load>
    match = modeRegex.match(message);
    if (match.hasMatch()) {
        int modeNumber = match.captured(1).toInt();  // Extract mode number (e.g., 0, 1, etc.)
        double loadValue = match.captured(2).toDouble();  // Extract the load value
        emit loadDataParsed(modeNumber, loadValue);  // Emit the parsed mode and load value
        //qDebug() << "Parsed Mode" << modeNumber << "Load Value:" << loadValue;
        return;
    }

    // Match against cycle count (CC)
    match = cycleCountRegex.match(message);
    if (match.hasMatch()) {
        int cycleCount = match.captured(1).toInt();  // Extract the cycle count
        emit cycleCountParsed(cycleCount);  // Emit the parsed cycle count
        //qDebug() << "Parsed Cycle Count:" << cycleCount;
        return;
    }

    // Match against Calibration value (CC)
    match = calSetRegex.match(message);
    if (match.hasMatch()) {
        double calV = match.captured(1).toInt();  // Extract the cycle count
        emit calParsed(calV);  // Emit the parsed cycle count
        //qDebug() << "Parsed Cycle Count:" << cycleCount;
        return;
    }

    // If no pattern is matched, log or handle the unrecognized data
    qDebug() << "Unrecognized Data Format:" << message;
}
