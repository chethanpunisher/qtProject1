/********************************************************************************
** Form generated from reading UI file 'calibrationwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONWIN_H
#define UI_CALIBRATIONWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calibrationWin
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_calibrationIput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_userName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *calibrationWin)
    {
        if (calibrationWin->objectName().isEmpty())
            calibrationWin->setObjectName("calibrationWin");
        calibrationWin->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(calibrationWin);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(calibrationWin);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_calibrationIput = new QLineEdit(calibrationWin);
        lineEdit_calibrationIput->setObjectName("lineEdit_calibrationIput");

        horizontalLayout->addWidget(lineEdit_calibrationIput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(calibrationWin);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(calibrationWin);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        lineEdit_userName = new QLineEdit(calibrationWin);
        lineEdit_userName->setObjectName("lineEdit_userName");

        horizontalLayout_3->addWidget(lineEdit_userName);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(calibrationWin);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        lineEdit_password = new QLineEdit(calibrationWin);
        lineEdit_password->setObjectName("lineEdit_password");

        horizontalLayout_4->addWidget(lineEdit_password);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_2 = new QPushButton(calibrationWin);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_5->addWidget(pushButton_2);

        lineEdit = new QLineEdit(calibrationWin);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(calibrationWin);

        QMetaObject::connectSlotsByName(calibrationWin);
    } // setupUi

    void retranslateUi(QDialog *calibrationWin)
    {
        calibrationWin->setWindowTitle(QCoreApplication::translate("calibrationWin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("calibrationWin", "Enter Calibration Value -", nullptr));
        pushButton->setText(QCoreApplication::translate("calibrationWin", "Calibrate", nullptr));
        label_2->setText(QCoreApplication::translate("calibrationWin", "USER NAME: ", nullptr));
        label_3->setText(QCoreApplication::translate("calibrationWin", "PASSWORD: ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("calibrationWin", "Enter calibration factor manually", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calibrationWin: public Ui_calibrationWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONWIN_H
