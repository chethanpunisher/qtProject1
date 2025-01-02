#include "jsonmanager.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QDir>

JsonManager::JsonManager(const QString& filePath, QObject* parent) : QObject(parent), filePath(filePath) {}

// Creates the JSON file if it does not exist
bool JsonManager::createJsonFile() {
    QFile file(filePath);
    if (file.exists()) return true;  // File already exists

    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(QJsonObject{{"samples", QJsonArray()}});
        file.write(doc.toJson());
        file.close();
        return true;
    }
    qWarning() << "Could not create JSON file:" << filePath;
    return false;
}

// Adds operation parameters for a new sample
bool JsonManager::addOperationParameters(const QJsonObject& parameters) {
    QJsonDocument doc = loadJsonDocument();
    QJsonObject rootObj = doc.object();
    QJsonArray samples = rootObj.value("samples").toArray();

    // Check if sample already exists
    QString sampleName = parameters.value("sampleName").toString();
    if (sampleExists(sampleName)) {
        qWarning() << "Sample with name" << sampleName << "already exists.";
        return false;
    }

    samples.append(parameters);  // Add new sample parameters
    rootObj["samples"] = samples;
    return saveJsonDocument(QJsonDocument(rootObj));
}

// Reads individual parameters for a sample
QJsonObject JsonManager::readParameters(const QString& sampleName) {
    QJsonDocument doc = loadJsonDocument();
    QJsonArray samples = doc.object().value("samples").toArray();

    for (const QJsonValue& sample : samples) {
        QJsonObject sampleObj = sample.toObject();
        if (sampleObj.value("sampleName").toString() == sampleName) {
            return sampleObj;  // Found the sample, return its parameters
        }
    }
    qWarning() << "Sample" << sampleName << "not found.";
    return QJsonObject();  // Return empty if not found
}

// Updates parameters for a specific sample
bool JsonManager::updateParameters(const QString& sampleName, const QJsonObject& updatedParams) {
    QJsonDocument doc = loadJsonDocument();
    QJsonObject rootObj = doc.object();
    QJsonArray samples = rootObj.value("samples").toArray();

    for (int i = 0; i < samples.size(); ++i) {
        QJsonObject sampleObj = samples[i].toObject();
        if (sampleObj.value("sampleName").toString() == sampleName) {
            for (auto key : updatedParams.keys()) {
                sampleObj[key] = updatedParams.value(key);  // Update parameters
            }
            samples[i] = sampleObj;  // Update array element
            rootObj["samples"] = samples;
            return saveJsonDocument(QJsonDocument(rootObj));
        }
    }
    qWarning() << "Sample" << sampleName << "not found for updating.";
    return false;
}

// Checks if a sample exists based on sample name
bool JsonManager::sampleExists(const QString& sampleName) {
    QJsonDocument doc = loadJsonDocument();
    QJsonArray samples = doc.object().value("samples").toArray();

    for (const QJsonValue& sample : samples) {
        if (sample.toObject().value("sampleName").toString() == sampleName) {
            return true;  // Sample exists
        }
    }
    return false;  // Sample not found
}

// Helper function to load JSON data from file
QJsonDocument JsonManager::loadJsonDocument() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open JSON file for reading:" << filePath;
        return QJsonDocument();
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    return doc;
}

// Helper function to save JSON data to file
bool JsonManager::saveJsonDocument(const QJsonDocument& doc) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open JSON file for writing:" << filePath;
        return false;
    }
    file.write(doc.toJson());
    file.close();
    return true;
}

// Loads parameters based on the sample index value
QJsonObject JsonManager::loadParametersByIndex(int index) {
    QJsonDocument doc = loadJsonDocument();
    QJsonArray samples = doc.object().value("samples").toArray();

    for (const QJsonValue& sample : samples) {
        QJsonObject sampleObj = sample.toObject();
        if (sampleObj.value("index").toInt() == index) {  // Check if index matches
            return sampleObj;  // Return the matching sample parameters
        }
    }
    qWarning() << "Sample with index" << index << "not found.";
    return QJsonObject();  // Return empty if not found
}

// Retrieves all sample parameters as a QJsonArray
QJsonArray JsonManager::getAllSamples() {
    QJsonDocument doc = loadJsonDocument();
    return doc.object().value("samples").toArray();
}

// Retrieves the sample with the highest "index" value
int JsonManager::getSampleWithHighestIndex() {
    QJsonDocument doc = loadJsonDocument();
    QJsonArray samples = doc.object().value("samples").toArray();

    QJsonObject highestIndexSample;
    int highestIndex = -1;  // Start with a minimum index

    // Iterate through each sample and find the one with the highest index
    for (const QJsonValue& sampleValue : samples) {
        QJsonObject sampleObj = sampleValue.toObject();
        int currentIndex = sampleObj.value("index").toInt();

        if (currentIndex > highestIndex) {
            highestIndex = currentIndex;
            highestIndexSample = sampleObj;
        }
    }

    if (highestIndexSample.isEmpty()) {
        qWarning() << "No samples found with index information.";
    } else {
        qDebug() << "Sample with highest index found:" << highestIndexSample;
    }

    return highestIndex;  // Returns the sample with the highest index, or empty if none found
}

// Updates an individual parameter for a specified sample
bool JsonManager::updateParameter(const QString& sampleName, const QString& parameterName, const QJsonValue& newValue) {
    // Load the JSON document
    QJsonDocument doc = loadJsonDocument();
    QJsonObject rootObject = doc.object();
    QJsonArray samples = rootObject.value("samples").toArray();

    bool sampleFound = false;

    // Iterate through each sample to find the matching sampleName
    for (int i = 0; i < samples.size(); ++i) {
        QJsonObject sampleObj = samples[i].toObject();

        // Check if the current sample has the specified sampleName
        if (sampleObj.value("sampleName").toString() == sampleName) {
            // Update the parameter with the new value
            sampleObj[parameterName] = newValue;

            // Replace the updated sample back in the array
            samples[i] = sampleObj;
            sampleFound = true;
            break;
        }
    }

    if (!sampleFound) {
        qWarning() << "Sample with name" << sampleName << "not found.";
        return false;
    }

    // Update the "samples" array in the root object
    rootObject["samples"] = samples;
    doc.setObject(rootObject);

    // Save the updated document back to the file
    return saveJsonDocument(doc);
}

// Adds a new parameter to an existing sample if the parameter does not already exist
bool JsonManager::addParameter(const QString& sampleName, const QString& parameterName, const QJsonValue& value) {
    // Load the JSON document
    QJsonDocument doc = loadJsonDocument();
    QJsonObject rootObject = doc.object();
    QJsonArray samples = rootObject.value("samples").toArray();

    bool sampleFound = false;

    // Iterate through each sample to find the matching sampleName
    for (int i = 0; i < samples.size(); ++i) {
        QJsonObject sampleObj = samples[i].toObject();

        // Check if the current sample has the specified sampleName
        if (sampleObj.value("sampleName").toString() == sampleName) {
            // Check if the parameter already exists
            if (!sampleObj.contains(parameterName)) {
                // Add the new parameter
                sampleObj[parameterName] = value;

                // Replace the updated sample back in the array
                samples[i] = sampleObj;
                sampleFound = true;
            } else {
                qWarning() << "Parameter" << parameterName << "already exists for sample" << sampleName;
                return false;
            }
            break;
        }
    }

    if (!sampleFound) {
        qWarning() << "Sample with name" << sampleName << "not found.";
        return false;
    }

    // Update the "samples" array in the root object
    rootObject["samples"] = samples;
    doc.setObject(rootObject);

    // Save the updated document back to the file
    return saveJsonDocument(doc);
}


// Deletes a sample by its name, removes its associated folder, and reorders the indices
bool JsonManager::deleteSample(const QString& sampleName) {
    QJsonDocument doc = loadJsonDocument();
    QJsonObject rootObj = doc.object();
    QJsonArray samples = rootObj.value("samples").toArray();

    bool sampleFound = false;
    QString folderToDelete;

    // Find and remove the sample by its name
    for (int i = 0; i < samples.size(); ++i) {
        QJsonObject sampleObj = samples[i].toObject();
        if (sampleObj.value("sampleName").toString() == sampleName) {
            // Save the folder path for deletion
            folderToDelete = sampleObj.value("excelFilePath").toString();

            // Remove the sample
            samples.removeAt(i);
            sampleFound = true;
            break;
        }
    }

    if (!sampleFound) {
        qWarning() << "Sample with name" << sampleName << "not found for deletion.";
        return false;
    }

    // Delete the folder if it exists
    if (!folderToDelete.isEmpty()) {
        QDir dir(folderToDelete);
        if (dir.exists()) {
            if (!dir.removeRecursively()) {
                qWarning() << "Failed to delete folder at" << folderToDelete;
            } else {
                qDebug() << "Folder at" << folderToDelete << "deleted successfully.";
            }
        } else {
            qWarning() << "Folder at" << folderToDelete << "does not exist.";
        }
    }

    // Reorder indices for the remaining samples
    for (int i = 0; i < samples.size(); ++i) {
        QJsonObject sampleObj = samples[i].toObject();
        sampleObj["index"] = i;  // Update index
        samples[i] = sampleObj; // Save updated sample
    }

    rootObj["samples"] = samples; // Update the root object
    doc.setObject(rootObj);

    // Save the updated document back to the file
    return saveJsonDocument(doc);
}

