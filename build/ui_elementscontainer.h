/********************************************************************************
** Form generated from reading UI file 'elementscontainer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEMENTSCONTAINER_H
#define UI_ELEMENTSCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_elementsContainer
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_sampleName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_frequency;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_stopCycle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_amplitude;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_setPoint;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_Set;
    QPushButton *pushButton_clear;
    QListWidget *recentOperationsListWidget;

    void setupUi(QDialog *elementsContainer)
    {
        if (elementsContainer->objectName().isEmpty())
            elementsContainer->setObjectName("elementsContainer");
        elementsContainer->resize(477, 602);
        verticalLayout_3 = new QVBoxLayout(elementsContainer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(elementsContainer);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        lineEdit_sampleName = new QLineEdit(elementsContainer);
        lineEdit_sampleName->setObjectName("lineEdit_sampleName");
        lineEdit_sampleName->setAutoFillBackground(false);
        lineEdit_sampleName->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px"));

        horizontalLayout_3->addWidget(lineEdit_sampleName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(elementsContainer);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        lineEdit_frequency = new QLineEdit(elementsContainer);
        lineEdit_frequency->setObjectName("lineEdit_frequency");
        lineEdit_frequency->setAutoFillBackground(false);
        lineEdit_frequency->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px"));

        horizontalLayout_5->addWidget(lineEdit_frequency);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(elementsContainer);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        lineEdit_stopCycle = new QLineEdit(elementsContainer);
        lineEdit_stopCycle->setObjectName("lineEdit_stopCycle");
        lineEdit_stopCycle->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px"));

        horizontalLayout_6->addWidget(lineEdit_stopCycle);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(elementsContainer);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        lineEdit_amplitude = new QLineEdit(elementsContainer);
        lineEdit_amplitude->setObjectName("lineEdit_amplitude");
        lineEdit_amplitude->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px"));

        horizontalLayout_7->addWidget(lineEdit_amplitude);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(elementsContainer);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        lineEdit_setPoint = new QLineEdit(elementsContainer);
        lineEdit_setPoint->setObjectName("lineEdit_setPoint");
        lineEdit_setPoint->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px"));

        horizontalLayout_8->addWidget(lineEdit_setPoint);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButton_Set = new QPushButton(elementsContainer);
        pushButton_Set->setObjectName("pushButton_Set");

        horizontalLayout_10->addWidget(pushButton_Set);

        pushButton_clear = new QPushButton(elementsContainer);
        pushButton_clear->setObjectName("pushButton_clear");

        horizontalLayout_10->addWidget(pushButton_clear);


        verticalLayout_2->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        recentOperationsListWidget = new QListWidget(elementsContainer);
        recentOperationsListWidget->setObjectName("recentOperationsListWidget");

        verticalLayout_3->addWidget(recentOperationsListWidget);

        verticalLayout_3->setStretch(0, 5);
        verticalLayout_3->setStretch(1, 3);

        retranslateUi(elementsContainer);

        QMetaObject::connectSlotsByName(elementsContainer);
    } // setupUi

    void retranslateUi(QDialog *elementsContainer)
    {
        elementsContainer->setWindowTitle(QCoreApplication::translate("elementsContainer", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("elementsContainer", "Sample Name -", nullptr));
        label_3->setText(QCoreApplication::translate("elementsContainer", "Frequency -", nullptr));
        label_5->setText(QCoreApplication::translate("elementsContainer", "Stop cycle -", nullptr));
        label_6->setText(QCoreApplication::translate("elementsContainer", "Amplitude - ", nullptr));
        label_8->setText(QCoreApplication::translate("elementsContainer", "Set point - ", nullptr));
        pushButton_Set->setText(QCoreApplication::translate("elementsContainer", "Set", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("elementsContainer", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class elementsContainer: public Ui_elementsContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEMENTSCONTAINER_H
