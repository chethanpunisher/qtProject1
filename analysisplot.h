#ifndef ANALYSISPLOT_H
#define ANALYSISPLOT_H

#include <QDialog>
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
#include <QPair>
#include <QFile>

class ExcelLoader2;

namespace Ui {
class AnalysisPlot;
}

class AnalysisPlot : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisPlot(QWidget *parent = nullptr);
    ~AnalysisPlot();
    QString filePath;

private:
    Ui::AnalysisPlot *ui;
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
    QPair<QString, QString> readJsonFile(const QString &filePath);

private slots:
    void startLoading(const QString &filePath);
    void updateProgress(int value);
    void onDataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax);
    void moveLeft();
    void moveRight();
    void on_moveRightButton_clicked();
    void on_moveLeftButton_clicked();
};


class ExcelLoader2 : public QObject {
    Q_OBJECT

public:
    explicit ExcelLoader2(const QString &filePath, QObject *parent = nullptr);

signals:
    void progressUpdated(int value);
    void dataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax);
    void finished();

public slots:
    void load();

private:
    QString filePath;

};

#endif // ANALYSISPLOT_H
