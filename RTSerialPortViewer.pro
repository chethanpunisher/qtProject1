#-------------------------------------------------
#
# Project created by QtCreator 2018-10-07T15:54:40
#
#-------------------------------------------------

QT += core gui widgets charts serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RTSerialPortViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)


SOURCES += \
        analysisplot.cpp \
        calibrationwin.cpp \
        dataparser.cpp \
        elementscontainer.cpp \
        excelhandler.cpp \
        jsonmanager.cpp \
        main.cpp \
        mainwindow.cpp \
        serialcomm.cpp \
        serialmanager.cpp \
        plotwindow.cpp \
        qcustomplot.cpp \
        worker.cpp

HEADERS += \
        analysisplot.h \
        calibrationwin.h \
        dataparser.h \
        elementscontainer.h \
        excelhandler.h \
        jsonmanager.h \
        mainwindow.h \
        operation.h \
        serialcomm.h \
        serialmanager.h \
        plotwindow.h \
        qcustomplot.h \
        worker.h

FORMS += \
        analysisplot.ui \
        calibrationwin.ui \
        elementscontainer.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
