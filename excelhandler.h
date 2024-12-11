#ifndef EXCELHANDLER_H
#define EXCELHANDLER_H

#include <QObject>
#include <QVariant>
#include "xlsxdocument.h"  // Include QXlsx library

class ExcelHandler : public QObject {
    Q_OBJECT

public:
    explicit ExcelHandler(QObject *parent = nullptr);
    ~ExcelHandler();

    bool createNewExcelFile(const QString &filePath);
    bool loadExistingExcelFile(const QString &filePath);
    bool writeValue(int row, int column, const QVariant &value);
    QVariant readValue(int row, int column);
    void saveAndClose();

private:
    QXlsx::Document *document;
    QString currentFilePath;
    bool fileLoaded;
};

#endif // EXCELHANDLER_H
