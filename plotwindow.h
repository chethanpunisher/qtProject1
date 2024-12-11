#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <QProgressBar>
#include <QThread>
#include <QString>
#include <QRegularExpression>
#include "jsonmanager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class ExcelLoader;


class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    PlotWindow(QWidget *parent = nullptr);
    ~PlotWindow();

    QString filePath;

private:
    QChart *chart;
    QChartView *chartView;
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QProgressBar *progressBar;
    int yMax,yMin;
    float f_xp;
    QString let;
    //MainWindow mainWindow;
    void setupChart();
    void setupUI();
    QString extractSample(const QString &input);


private slots:
    void startLoading(const QString &filePath);
    void updateProgress(int value);
    void onDataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax);
    void moveLeft();
    void moveRight();

public slots:




};


class ExcelLoader : public QObject {
    Q_OBJECT

public:
    explicit ExcelLoader(const QString &filePath, QObject *parent = nullptr);

signals:
    void progressUpdated(int value);
    void dataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax);
    void finished();

public slots:
    void load();

private:
    QString filePath;

};


#endif // PLOTWINDOW_H
