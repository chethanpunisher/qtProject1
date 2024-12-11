#ifndef ELEMENTSCONTAINER_H
#define ELEMENTSCONTAINER_H

#include <QDialog>
#include <QListWidgetItem>
#include <QJsonObject>
#include <QJsonArray>
#include <QCompleter>
#include "jsonmanager.h"
#include "xlsxdocument.h"

namespace Ui {
class elementsContainer;
}

class elementsContainer : public QDialog
{
    Q_OBJECT

public:
    explicit elementsContainer(QWidget *parent = nullptr);
    ~elementsContainer();

signals:
    void dataAvailable(int index);
    void saveData();

private slots:
    void on_pushButton_Set_clicked();
    void on_pushButton_clear_clicked();
    void onRecentOperationClicked(QListWidgetItem *item);

private:
    Ui::elementsContainer *ui;

    QString excelFilePath;
    QString FolderCreation();
    QString getBatchString(int number);

    void displayRecentOperations();
    void performSearch();
    void saveExcel();
    void dialogOpen();
    QList<QJsonObject> listSamplesByAscendingIndex(JsonManager &jsonManager);

    bool excelSaveFlg;
    bool excelUpdateFlg;
    bool paramSetFlg;
    bool existingSel;
    int selIndex;
    int In;
    int x;
    int columnCount;
    bool en;
    QXlsx::Document xlsx;
    QVector<QString> recentSearches;
    QCompleter *completer;
};

#endif // ELEMENTSCONTAINER_H
