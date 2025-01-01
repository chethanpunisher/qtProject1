/********************************************************************************
** Form generated from reading UI file 'analysisplot.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISPLOT_H
#define UI_ANALYSISPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AnalysisPlot
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *NameLabel;
    QLabel *AddrLabel;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox_sampleSelec;
    QComboBox *comboBox_batchSelec;
    QHBoxLayout *horizontalLayout_6;
    QLabel *SampleHeading;
    QLabel *sampleLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLabel *AmplitudeLabel;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *startTimeLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLabel *stopTimeLabel;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *frequencyLabel;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *setPointLabel;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *startDateLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *endDateLabel;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QLabel *stopCycleLabel;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *moveLeftButton;
    QPushButton *moveRightButton;

    void setupUi(QDialog *AnalysisPlot)
    {
        if (AnalysisPlot->objectName().isEmpty())
            AnalysisPlot->setObjectName("AnalysisPlot");
        AnalysisPlot->resize(883, 628);
        verticalLayout_5 = new QVBoxLayout(AnalysisPlot);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        NameLabel = new QLabel(AnalysisPlot);
        NameLabel->setObjectName("NameLabel");
        QFont font;
        font.setPointSize(28);
        NameLabel->setFont(font);
        NameLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));
        NameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(NameLabel);

        AddrLabel = new QLabel(AnalysisPlot);
        AddrLabel->setObjectName("AddrLabel");
        AddrLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));
        AddrLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(AddrLabel);


        verticalLayout_4->addLayout(verticalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        comboBox_sampleSelec = new QComboBox(AnalysisPlot);
        comboBox_sampleSelec->setObjectName("comboBox_sampleSelec");

        horizontalLayout_12->addWidget(comboBox_sampleSelec);

        comboBox_batchSelec = new QComboBox(AnalysisPlot);
        comboBox_batchSelec->setObjectName("comboBox_batchSelec");

        horizontalLayout_12->addWidget(comboBox_batchSelec);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        SampleHeading = new QLabel(AnalysisPlot);
        SampleHeading->setObjectName("SampleHeading");
        SampleHeading->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_6->addWidget(SampleHeading);

        sampleLabel = new QLabel(AnalysisPlot);
        sampleLabel->setObjectName("sampleLabel");
        sampleLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_6->addWidget(sampleLabel);

        horizontalLayout_6->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_4 = new QLabel(AnalysisPlot);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_7->addWidget(label_4);

        AmplitudeLabel = new QLabel(AnalysisPlot);
        AmplitudeLabel->setObjectName("AmplitudeLabel");
        AmplitudeLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_7->addWidget(AmplitudeLabel);

        label_3 = new QLabel(AnalysisPlot);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_7->setStretch(1, 2);
        horizontalLayout_7->setStretch(3, 5);

        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_5 = new QLabel(AnalysisPlot);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_8->addWidget(label_5);

        startTimeLabel = new QLabel(AnalysisPlot);
        startTimeLabel->setObjectName("startTimeLabel");
        startTimeLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_8->addWidget(startTimeLabel);

        horizontalLayout_8->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_6 = new QLabel(AnalysisPlot);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_9->addWidget(label_6);

        stopTimeLabel = new QLabel(AnalysisPlot);
        stopTimeLabel->setObjectName("stopTimeLabel");
        stopTimeLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_9->addWidget(stopTimeLabel);

        horizontalLayout_9->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_7 = new QLabel(AnalysisPlot);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout->addWidget(label_7);

        frequencyLabel = new QLabel(AnalysisPlot);
        frequencyLabel->setObjectName("frequencyLabel");
        frequencyLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout->addWidget(frequencyLabel);

        label_2 = new QLabel(AnalysisPlot);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(3, 5);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_8 = new QLabel(AnalysisPlot);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_2->addWidget(label_8);

        setPointLabel = new QLabel(AnalysisPlot);
        setPointLabel->setObjectName("setPointLabel");
        setPointLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_2->addWidget(setPointLabel);

        label_11 = new QLabel(AnalysisPlot);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_2->addWidget(label_11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(3, 5);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_9 = new QLabel(AnalysisPlot);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_3->addWidget(label_9);

        startDateLabel = new QLabel(AnalysisPlot);
        startDateLabel->setObjectName("startDateLabel");
        startDateLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_3->addWidget(startDateLabel);

        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_10 = new QLabel(AnalysisPlot);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_10);

        endDateLabel = new QLabel(AnalysisPlot);
        endDateLabel->setObjectName("endDateLabel");
        endDateLabel->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_4->addWidget(endDateLabel);

        horizontalLayout_4->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_10->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label = new QLabel(AnalysisPlot);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_11->addWidget(label);

        stopCycleLabel = new QLabel(AnalysisPlot);
        stopCycleLabel->setObjectName("stopCycleLabel");
        stopCycleLabel->setFont(font1);

        horizontalLayout_11->addWidget(stopCycleLabel);

        horizontalLayout_11->setStretch(0, 10);
        horizontalLayout_11->setStretch(1, 9);

        verticalLayout_7->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");

        verticalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        moveLeftButton = new QPushButton(AnalysisPlot);
        moveLeftButton->setObjectName("moveLeftButton");

        horizontalLayout_5->addWidget(moveLeftButton);

        moveRightButton = new QPushButton(AnalysisPlot);
        moveRightButton->setObjectName("moveRightButton");

        horizontalLayout_5->addWidget(moveRightButton);


        verticalLayout_5->addLayout(horizontalLayout_5);


        retranslateUi(AnalysisPlot);

        QMetaObject::connectSlotsByName(AnalysisPlot);
    } // setupUi

    void retranslateUi(QDialog *AnalysisPlot)
    {
        AnalysisPlot->setWindowTitle(QCoreApplication::translate("AnalysisPlot", "Dialog", nullptr));
        NameLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        AddrLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        SampleHeading->setText(QCoreApplication::translate("AnalysisPlot", "Sample Name :", nullptr));
        sampleLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("AnalysisPlot", "Amplitude :", nullptr));
        AmplitudeLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("AnalysisPlot", "Ton", nullptr));
        label_5->setText(QCoreApplication::translate("AnalysisPlot", "Start Time :", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("AnalysisPlot", "Stop Time :", nullptr));
        stopTimeLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("AnalysisPlot", "Frequency :", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("AnalysisPlot", "Hz", nullptr));
        label_8->setText(QCoreApplication::translate("AnalysisPlot", "Set Point :", nullptr));
        setPointLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("AnalysisPlot", "Ton", nullptr));
        label_9->setText(QCoreApplication::translate("AnalysisPlot", "Start Date :", nullptr));
        startDateLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("AnalysisPlot", "End Date :", nullptr));
        endDateLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("AnalysisPlot", "Stop Cycle :", nullptr));
        stopCycleLabel->setText(QCoreApplication::translate("AnalysisPlot", "TextLabel", nullptr));
        moveLeftButton->setText(QCoreApplication::translate("AnalysisPlot", "Move Left", nullptr));
        moveRightButton->setText(QCoreApplication::translate("AnalysisPlot", "Move Right", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnalysisPlot: public Ui_AnalysisPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISPLOT_H
