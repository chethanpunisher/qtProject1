#include "plotwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include <xlsxdocument.h>
#include <limits>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>

QString jsonFilePath2 = "sampleData.json";
JsonManager jsonManager2(jsonFilePath2);

ExcelLoader::ExcelLoader(const QString &filePath, QObject *parent)
    : QObject(parent), filePath(filePath) {}

void ExcelLoader::load() {
    QXlsx::Document xlsx(filePath);
    QVector<QPointF> data;
    qreal yMin = std::numeric_limits<qreal>::max();
    qreal yMax = std::numeric_limits<qreal>::min();

    qDebug() << filePath;

    int rowLimit = 800000;   // Limit rows per column block
    int currentCol = 1;  // Start at column 1 (A)

    while (true) {
        QString slNoHeader = xlsx.read(1, currentCol).toString();
        QString sampleNameHeader = xlsx.read(1, currentCol + 1).toString();

        if (slNoHeader.isEmpty() || sampleNameHeader.isEmpty()) {
            break;  // End when no more data is found
        }

        qDebug() << "Reading Data from Columns:" << slNoHeader << "and" << sampleNameHeader;

        // Read each row in the block (up to rowLimit)
        for (int row = 2; row <= rowLimit + 1; ++row) {
            QVariant slNoValue = xlsx.read(row, currentCol);
            QVariant sampleNameValue = xlsx.read(row, currentCol + 1);

            if (slNoValue.isNull() && sampleNameValue.isNull()) {
                continue;  // Skip empty rows
            }

            qreal x = slNoValue.toInt() / 50.0;    // Scale down X-axis by 1/50
            qreal y = sampleNameValue.toInt() / 1000.0;  // Scale down Y-axis by 1/1000
            data.append(QPointF(x, y));

            if (y < yMin) yMin = y;
            if (y > yMax) yMax = y;

            emit progressUpdated(row - 1);
            qDebug() << "Sl No:" << slNoValue.toInt() << ", Sample Name:" << sampleNameValue.toString();
        }

        currentCol += 2;  // Move to the next set of columns
    }

    emit dataLoaded(data, yMin, yMax);
    emit finished();
}



PlotWindow::PlotWindow(QWidget *parent)
    : QMainWindow(parent),
    chart(new QChart()),
    chartView(new QChartView(chart)),
    series(new QLineSeries()),
    axisX(new QValueAxis()),
    axisY(new QValueAxis()),
    leftButton(new QPushButton("Move Left")),
    rightButton(new QPushButton("Move Right")),
    progressBar(new QProgressBar(this))
{


    // Load the Excel file
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Open Excel File",
                                                    QDir::homePath(),
                                                    "Excel Files (*.xlsx)");
    let = extractSample(filePath);
    qDebug()<<let;
    resize(800, 600); // Set the initial size of the PlotWindow to 800x600
    setupChart();
    setupUI();
    if (!filePath.isEmpty()) {
        startLoading(filePath);
    } else {
        QMessageBox::warning(this, "Cancelled", "File open operation was cancelled.");
    }
}

PlotWindow::~PlotWindow() {
}

void PlotWindow::setupChart()
{
    chart->setTitle("Sl No vs Sample");
    chart->addSeries(series);
    chart->createDefaultAxes();

    axisX->setTitleText("Sl No");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(6);
    chart->setAxisX(axisX, series);

    axisY->setTitleText("Sample");
    axisY->setLabelFormat("%d");
    axisY->setTickCount(10);
    chart->setAxisY(axisY, series);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
}

void PlotWindow::setupUI()
{
    QJsonObject sampleDis = jsonManager2.readParameters(let);
    // Parameter labels and line edits
    QLabel *sampleNameLabel = new QLabel("Sample Name:");
    QLabel *sampleNameEdit = new QLabel;
    sampleNameEdit->setText(sampleDis.value("sampleName").toString());
    sampleNameEdit->setStyleSheet("border: 2px  solid lightblue; border-radius: 5px");
    qDebug()<<sampleDis.value("sampleName");

    QLabel *frequencyLabel = new QLabel("Frequency:");
    QLabel *frequencyEdit = new QLabel;
    frequencyEdit->setText(QString::number(sampleDis.value("frequency").toDouble()));
    frequencyEdit->setStyleSheet("border: 2px  solid lightblue; border-radius: 5px");

    QLabel *setPointLabel = new QLabel("Set Point:");
    QLabel *setPointEdit = new QLabel;
    setPointEdit->setText(QString::number(sampleDis.value("setPoint").toDouble()/1000));
    setPointEdit->setStyleSheet("border: 2px  solid lightblue; border-radius: 5px");

    QLabel *amplitudeLabel = new QLabel("Amplitude:");
    QLabel *amplitudeEdit = new QLabel;
    amplitudeEdit->setText(QString::number(sampleDis.value("amplitude").toDouble()/1000));
    amplitudeEdit->setStyleSheet("border: 2px  solid lightblue; border-radius: 5px");

    QLabel *stopCycleLabel = new QLabel("Stop Cycle:");
    QLabel *stopCycleEdit = new QLabel;
    stopCycleEdit->setText(QString::number(sampleDis.value("stopCycle").toDouble()));
    stopCycleEdit->setStyleSheet("border: 2px  solid lightblue; border-radius: 5px");

    // Form layout for operation parameters
    QFormLayout *parameterLayout = new QFormLayout;
    parameterLayout->addRow(sampleNameLabel, sampleNameEdit);
    parameterLayout->addRow(frequencyLabel, frequencyEdit);
    parameterLayout->addRow(setPointLabel, setPointEdit);
    parameterLayout->addRow(amplitudeLabel, amplitudeEdit);
    parameterLayout->addRow(stopCycleLabel, stopCycleEdit);

    // Connect button signals to slots
    connect(leftButton, &QPushButton::clicked, this, &PlotWindow::moveLeft);
    connect(rightButton, &QPushButton::clicked, this, &PlotWindow::moveRight);

    // Layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(leftButton);
    buttonLayout->addWidget(rightButton);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(parameterLayout);  // Add parameter layout at the top
    mainLayout->addWidget(chartView);
    mainLayout->addWidget(progressBar);      // Add the progress bar to the layout
    mainLayout->addLayout(buttonLayout);

    // Set up the main widget
    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}


void PlotWindow::startLoading(const QString &filePath)
{
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setVisible(true);

    // Create a new thread
    QThread *thread = new QThread;
    ExcelLoader *loader = new ExcelLoader(filePath);
    loader->moveToThread(thread);

    // Connect signals and slots
    connect(thread, &QThread::started, loader, &ExcelLoader::load);
    connect(loader, &ExcelLoader::progressUpdated, this, &PlotWindow::updateProgress);
    connect(loader, &ExcelLoader::dataLoaded, this, &PlotWindow::onDataLoaded);
    connect(loader, &ExcelLoader::finished, thread, &QThread::quit);
    connect(loader, &ExcelLoader::finished, loader, &ExcelLoader::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void PlotWindow::updateProgress(int value)
{
    progressBar->setValue(value);
}

void PlotWindow::onDataLoaded(QVector<QPointF> data, qreal yMin, qreal yMax)
{
    series->replace(data);
    axisX->setRange(data.first().x(), data.last().x() - (data.last().x() - 5));
    axisY->setRange(0, yMax+2);

    progressBar->setVisible(false);
}

void PlotWindow::moveLeft()
{
    qreal step = (axisX->max() - axisX->min()) * 1;
    axisX->setRange(axisX->min() - step, axisX->max() - step);
}

void PlotWindow::moveRight()
{
    qreal step = (axisX->max() - axisX->min()) * 1;
    axisX->setRange(axisX->min() + step, axisX->max() + step);
}

QString PlotWindow::extractSample(const QString &input) {
    // Define the regular expression to match "sample" followed by any number
    QRegularExpression regex("sample\\d+");
    QRegularExpressionMatch match = regex.match(input);

    // Check if the regex matched successfully and return the matched text
    if (match.hasMatch()) {
        return match.captured(0); // captured(0) returns the full match, e.g., "sample4"
    }

    // If no match is found, return an empty string or handle as needed
    return QString();
}
