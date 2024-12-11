/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *EXIT;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_sampleName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_frequency;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_stopCycle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_amplitude;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *label_setPoint;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_parameters;
    QPushButton *pushButton_save;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_currentCycle;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QComboBox *comboBox_mode;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_11;
    QLabel *label_Torque;
    QLabel *label_7;
    QLabel *label_timeLapse;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QComboBox *comboBox_comPort;
    QPushButton *pushButton_comConnect;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_portStatus;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(953, 519);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        EXIT = new QPushButton(centralWidget);
        EXIT->setObjectName("EXIT");

        horizontalLayout_2->addWidget(EXIT);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName("pushButton_open");

        horizontalLayout_2->addWidget(pushButton_open);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_3->addWidget(label);

        label_sampleName = new QLabel(centralWidget);
        label_sampleName->setObjectName("label_sampleName");
        label_sampleName->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_3->addWidget(label_sampleName);

        horizontalLayout_3->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_5->addWidget(label_3);

        label_frequency = new QLabel(centralWidget);
        label_frequency->setObjectName("label_frequency");
        label_frequency->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_5->addWidget(label_frequency);

        horizontalLayout_5->setStretch(0, 8);
        horizontalLayout_5->setStretch(1, 15);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_6->addWidget(label_5);

        label_stopCycle = new QLabel(centralWidget);
        label_stopCycle->setObjectName("label_stopCycle");
        label_stopCycle->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_6->addWidget(label_stopCycle);

        horizontalLayout_6->setStretch(0, 8);
        horizontalLayout_6->setStretch(1, 15);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_7->addWidget(label_6);

        label_amplitude = new QLabel(centralWidget);
        label_amplitude->setObjectName("label_amplitude");
        label_amplitude->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_7->addWidget(label_amplitude);

        horizontalLayout_7->setStretch(0, 7);
        horizontalLayout_7->setStretch(1, 13);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_8->addWidget(label_8);

        label_setPoint = new QLabel(centralWidget);
        label_setPoint->setObjectName("label_setPoint");
        label_setPoint->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px; background-color: lightblue"));

        horizontalLayout_8->addWidget(label_setPoint);

        horizontalLayout_8->setStretch(0, 7);
        horizontalLayout_8->setStretch(1, 13);

        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName("pushButton_start");

        horizontalLayout_9->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName("pushButton_stop");

        horizontalLayout_9->addWidget(pushButton_stop);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButton_delete = new QPushButton(centralWidget);
        pushButton_delete->setObjectName("pushButton_delete");

        horizontalLayout_10->addWidget(pushButton_delete);

        pushButton_parameters = new QPushButton(centralWidget);
        pushButton_parameters->setObjectName("pushButton_parameters");

        horizontalLayout_10->addWidget(pushButton_parameters);


        verticalLayout->addLayout(horizontalLayout_10);

        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName("pushButton_save");

        verticalLayout->addWidget(pushButton_save);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");

        horizontalLayout->addLayout(gridLayout);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 90);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_currentCycle = new QLineEdit(centralWidget);
        lineEdit_currentCycle->setObjectName("lineEdit_currentCycle");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(20);
        font.setBold(true);
        lineEdit_currentCycle->setFont(font);
        lineEdit_currentCycle->setStyleSheet(QString::fromUtf8("border: 2px  solid blue; border-radius: 5px"));

        horizontalLayout_4->addWidget(lineEdit_currentCycle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        comboBox_mode = new QComboBox(centralWidget);
        comboBox_mode->setObjectName("comboBox_mode");

        horizontalLayout_4->addWidget(comboBox_mode);

        pushButton_up = new QPushButton(centralWidget);
        pushButton_up->setObjectName("pushButton_up");

        horizontalLayout_4->addWidget(pushButton_up);

        pushButton_down = new QPushButton(centralWidget);
        pushButton_down->setObjectName("pushButton_down");

        horizontalLayout_4->addWidget(pushButton_down);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName("label_11");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("border: 2px  solid orange; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_11);

        label_Torque = new QLabel(centralWidget);
        label_Torque->setObjectName("label_Torque");
        label_Torque->setFont(font1);
        label_Torque->setStyleSheet(QString::fromUtf8("border: 2px  solid red; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_Torque);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_7);

        label_timeLapse = new QLabel(centralWidget);
        label_timeLapse->setObjectName("label_timeLapse");
        label_timeLapse->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_4->addWidget(label_timeLapse);

        horizontalLayout_4->setStretch(1, 12);
        horizontalLayout_4->setStretch(2, 10);
        horizontalLayout_4->setStretch(4, 10);
        horizontalLayout_4->setStretch(8, 1);
        horizontalLayout_4->setStretch(9, 8);
        horizontalLayout_4->setStretch(11, 8);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("border: 2px  solid lightblue; border-radius: 5px"));

        horizontalLayout_11->addWidget(label_9);

        comboBox_comPort = new QComboBox(centralWidget);
        comboBox_comPort->setObjectName("comboBox_comPort");

        horizontalLayout_11->addWidget(comboBox_comPort);

        pushButton_comConnect = new QPushButton(centralWidget);
        pushButton_comConnect->setObjectName("pushButton_comConnect");

        horizontalLayout_11->addWidget(pushButton_comConnect);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_11->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_11->addWidget(pushButton);

        label_portStatus = new QLabel(centralWidget);
        label_portStatus->setObjectName("label_portStatus");
        QFont font2;
        font2.setBold(true);
        label_portStatus->setFont(font2);
        label_portStatus->setStyleSheet(QString::fromUtf8("color : red"));

        horizontalLayout_11->addWidget(label_portStatus);

        horizontalLayout_11->setStretch(0, 8);
        horizontalLayout_11->setStretch(3, 60);
        horizontalLayout_11->setStretch(6, 10);

        verticalLayout_3->addLayout(horizontalLayout_11);


        verticalLayout_2->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MABL:: Real Time Serial Plotter", nullptr));
        EXIT->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sample Name -", nullptr));
        label_sampleName->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Frequency -", nullptr));
        label_frequency->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Stop cycle -", nullptr));
        label_stopCycle->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Amplitude - ", nullptr));
        label_amplitude->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Set point - ", nullptr));
        label_setPoint->setText(QString());
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_parameters->setText(QCoreApplication::translate("MainWindow", "Set Parameters", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Current Cycle -", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Mode :", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "LOAD :", nullptr));
        label_Torque->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Time lapse :", nullptr));
        label_timeLapse->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Port -", nullptr));
        pushButton_comConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "TARE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        label_portStatus->setText(QCoreApplication::translate("MainWindow", "COM : inActive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
