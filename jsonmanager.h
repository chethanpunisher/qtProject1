#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QString>

class JsonManager : public QObject {
    Q_OBJECT

public:
    explicit JsonManager(const QString& filePath, QObject* parent = nullptr);

    bool createJsonFile();  // Creates JSON file if not present
    bool addOperationParameters(const QJsonObject& parameters);  // Adds parameters for a new sample
    QJsonObject readParameters(const QString& sampleName);  // Reads parameters of a sample by name
    bool updateParameters(const QString& sampleName, const QJsonObject& updatedParams);  // Updates parameters
    bool sampleExists(const QString& sampleName);  // Checks if the sample exists by name
    QJsonObject loadParametersByIndex(int index);  // Loads parameters by index value
    QJsonArray getAllSamples();  // New function to get all samples
    int getSampleWithHighestIndex();
    bool updateParameter(const QString& sampleName, const QString& parameterName, const QJsonValue& newValue);  // New function for updating individual parameters
    bool addParameter(const QString& sampleName, const QString& parameterName, const QJsonValue& value);  // New function to add a parameter
    bool deleteSample(const QString& sampleName);

private:
    QString filePath;  // Path to the JSON file

    QJsonDocument loadJsonDocument();  // Helper function to load JSON data
    bool saveJsonDocument(const QJsonDocument& doc);  // Helper function to save JSON data
};

#endif // JSONMANAGER_H
