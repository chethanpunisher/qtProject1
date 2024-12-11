#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtSerialPort>
#include <QVector>
#include <plotwindow.h>
#include <xlsxdocument.h>
#include <QWidget>
#include <QLineEdit>
#include <QCompleter>
#include <QStringList>
#include <QPushButton>
#include <QLabel>
#include <elementscontainer.h>
#include "operation.h"
#include <calibrationwin.h>
#include <serialcomm.h>
#include <memory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>
#include <QRegularExpression>
#include "dataparser.h"
#include "excelhandler.h"
#include "worker.h"
#include <QThread>
#include "analysisplot.h"
#include <QPair>
#include <QDialog>

class WelcomeDialog;

QT_BEGIN_NAMESPACE

    namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_comboBoxADCRes_currentIndexChanged(const QString &arg1);
    void on_comboBoxChannel_currentIndexChanged(const QString &arg1);
    void updateSineWave();
    void on_EXIT_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_delete_clicked();

    //void performSearch();

    void parameters(int index);
    void updateRecentOperations();
    void on_pushButton_parameters_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_clicked();

    void updateComPorts();

    void onComboBoxIndexChanged(int index);

    void monitorConnection();

    void updateTimeLapse();

    void on_comboBox_mode_currentIndexChanged1(int index);


    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void onSerialDataReceived(const QString &data1);
    void onSerialPortError(const QString &error);


    void on_pushButton_comConnect_clicked();

    void on_pushButton_up_pressed();

    void on_pushButton_up_released();

    void on_pushButton_down_pressed();

    void on_pushButton_down_released();

    void on_pushButton_2_clicked();

    void updateLoadValue(int modeNumber, double loadValue);

    void updateCycleCount(int cycleCount);

    QString getBatchString(int number);

    void threadFunc();

    QPair<QString, QString> getCurrentDateAndTime();

    bool requestPasscode(const QString &correctPasscode);

    double updateWave();

private:
    void initUI();
    void serialInit(QString port);
    void excelInit();
    void excelWrite(int x, int y);
    void updateAxis();
    void excupdate(int x, int y);
    int findLastNonEmptyRow(QXlsx::Document &xlsxDoc1);
    void startTimer();
    void initializeSerialPort(const QString port);
    void writeSerial(const QString data1);
    void errorMessage(int state);
    void readJsonConfig(const QString &filePath);
    void updateExcXInJson(const QString &filePath, const QString &sampleName, double newExcX);
    void getExcXInJson(const QString &filePath, const QString &sampleName, int newExcX);
    void loadLabelUp();
    void readProcess(QString data1);
    PlotWindow *plotWindow;
    AnalysisPlot *analysisPlot;
    elementsContainer* ec;
    calibrationWin *cw;
    QSerialPort *serialPort;
    Ui::MainWindow *ui;
    QVector<double> xData, yData;
    QChart *chart;
    bool flg;
    bool en;
    int number;
    int sc;
    QList<QLineSeries *> series;
    QXlsx::Document *xlsx;
    //std::unique_ptr<QXlsx::Document> xlsx;
    static int x;  // Used to track the current x-axis position
    QCompleter *completer;
    QStringList recentSearches;
    QLabel *resultLabel;
    Operation op;
    QList<Operation> operations;
    QString sN, frq, sP, amp, sC;
    QString excFilePath;
    bool excSaveFlag;
    QXlsx::Document *xlsxDoc;
    bool excUpdateFlg;
    bool opFlg;
    int timeOutNum;
    int preV;
    int preVx;
    QString portName;
    QString portDevice;
    QTimer *connectionMonitorTimer;
    QTimer *loadLabelUpdate;
    QList<QSerialPortInfo> availablePorts;
    int elapsedTime;
    int globalY;
    bool torqueFlg;
    bool mode;
    bool portFlg;
    QLineSeries *ser;
    QChartView *chartView;
    SerialComm *serialComm;
    int columnCount;
    bool exFlg;
    bool startFlg;
    int caseCount;
    QString serialBuffer;
    DataParser* dataParser;
    ExcelHandler* excelHandler;
    float f_x;
    int sindex;
    QJsonObject jsonObject;
    ProcessCondition processCondition;
    QString modAmp;
    QString modSp;
};

class WelcomeDialog : public QDialog {
    Q_OBJECT
public:
    explicit WelcomeDialog(const QString &imagePath, QWidget *parent = nullptr);
private:
    QTimer *timer;
};

#endif // MAINWINDOW_H
