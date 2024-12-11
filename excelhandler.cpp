#include "ExcelHandler.h"
#include <QDebug>

ExcelHandler::ExcelHandler(QObject *parent)
    : QObject(parent), document(nullptr), fileLoaded(false) {}

ExcelHandler::~ExcelHandler() {
    saveAndClose();
    delete document;
}

bool ExcelHandler::createNewExcelFile(const QString &filePath) {
    if (document) delete document;  // Clean up previous document if it exists

    document = new QXlsx::Document;
    currentFilePath = filePath;
    fileLoaded = true;

    qDebug() << "New Excel file created.";
    return true;
}

bool ExcelHandler::loadExistingExcelFile(const QString &filePath) {
    if (document) delete document;  // Clean up previous document if it exists

    document = new QXlsx::Document(filePath);
    if (!document->load()) {
        qDebug() << "Failed to load Excel file:" << filePath;
        fileLoaded = false;
        return false;
    }

    currentFilePath = filePath;
    fileLoaded = true;
    qDebug() << "Excel file loaded from:" << filePath;
    return true;
}

bool ExcelHandler::writeValue(int row, int column, const QVariant &value) {
    if (!fileLoaded || !document) {
        qDebug() << "No Excel file loaded.";
        return false;
    }

    // Convert row and column to Excel cell notation
    QString cell = QXlsx::CellReference(row, column).toString();
    document->write(cell, value);

    qDebug() << "Value written to cell (" << row << "," << column << "):" << value;
    return true;
}

QVariant ExcelHandler::readValue(int row, int column) {
    if (!fileLoaded || !document) {
        qDebug() << "No Excel file loaded.";
        return QVariant();
    }

    // Convert row and column to Excel cell notation
    QString cell = QXlsx::CellReference(row, column).toString();
    QVariant value = document->read(cell);

    qDebug() << "Value read from cell (" << row << "," << column << "):" << value;
    return value;
}

void ExcelHandler::saveAndClose() {
    if (fileLoaded && document) {
        document->saveAs(currentFilePath);
        qDebug() << "Excel file saved to:" << currentFilePath;
    }
}
