/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_comboBoxADCRes_currentIndexChanged",
    "",
    "arg1",
    "on_comboBoxChannel_currentIndexChanged",
    "updateSineWave",
    "on_EXIT_clicked",
    "on_pushButton_start_clicked",
    "on_pushButton_open_clicked",
    "on_pushButton_stop_clicked",
    "on_pushButton_delete_clicked",
    "parameters",
    "index",
    "updateRecentOperations",
    "on_pushButton_parameters_clicked",
    "on_pushButton_save_clicked",
    "updateComPorts",
    "onComboBoxIndexChanged",
    "monitorConnection",
    "updateTimeLapse",
    "on_comboBox_mode_currentIndexChanged1",
    "on_pushButton_up_clicked",
    "on_pushButton_down_clicked",
    "onSerialDataReceived",
    "data1",
    "onSerialPortError",
    "error",
    "on_pushButton_comConnect_clicked",
    "on_pushButton_up_pressed",
    "on_pushButton_up_released",
    "on_pushButton_down_pressed",
    "on_pushButton_down_released",
    "on_pushButton_2_clicked",
    "updateLoadValue",
    "modeNumber",
    "loadValue",
    "updateCycleCount",
    "cycleCount",
    "getBatchString",
    "number",
    "threadFunc",
    "getCurrentDateAndTime",
    "std::pair<QString,QString>",
    "requestPasscode",
    "correctPasscode",
    "updateWave",
    "on_comboBox_existingParamSelec_currentTextChanged",
    "on_comboBox_existingParamSelec_currentIndexChanged",
    "on_pushButton_calibra_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  236,    2, 0x08,    1 /* Private */,
       4,    1,  239,    2, 0x08,    3 /* Private */,
       5,    0,  242,    2, 0x08,    5 /* Private */,
       6,    0,  243,    2, 0x08,    6 /* Private */,
       7,    0,  244,    2, 0x08,    7 /* Private */,
       8,    0,  245,    2, 0x08,    8 /* Private */,
       9,    0,  246,    2, 0x08,    9 /* Private */,
      10,    0,  247,    2, 0x08,   10 /* Private */,
      11,    1,  248,    2, 0x08,   11 /* Private */,
      13,    0,  251,    2, 0x08,   13 /* Private */,
      14,    0,  252,    2, 0x08,   14 /* Private */,
      15,    0,  253,    2, 0x08,   15 /* Private */,
      16,    0,  254,    2, 0x08,   16 /* Private */,
      17,    1,  255,    2, 0x08,   17 /* Private */,
      18,    0,  258,    2, 0x08,   19 /* Private */,
      19,    0,  259,    2, 0x08,   20 /* Private */,
      20,    1,  260,    2, 0x08,   21 /* Private */,
      21,    0,  263,    2, 0x08,   23 /* Private */,
      22,    0,  264,    2, 0x08,   24 /* Private */,
      23,    1,  265,    2, 0x08,   25 /* Private */,
      25,    1,  268,    2, 0x08,   27 /* Private */,
      27,    0,  271,    2, 0x08,   29 /* Private */,
      28,    0,  272,    2, 0x08,   30 /* Private */,
      29,    0,  273,    2, 0x08,   31 /* Private */,
      30,    0,  274,    2, 0x08,   32 /* Private */,
      31,    0,  275,    2, 0x08,   33 /* Private */,
      32,    0,  276,    2, 0x08,   34 /* Private */,
      33,    2,  277,    2, 0x08,   35 /* Private */,
      36,    1,  282,    2, 0x08,   38 /* Private */,
      38,    1,  285,    2, 0x08,   40 /* Private */,
      40,    0,  288,    2, 0x08,   42 /* Private */,
      41,    0,  289,    2, 0x08,   43 /* Private */,
      43,    1,  290,    2, 0x08,   44 /* Private */,
      45,    0,  293,    2, 0x08,   46 /* Private */,
      46,    1,  294,    2, 0x08,   47 /* Private */,
      47,    1,  297,    2, 0x08,   49 /* Private */,
      48,    0,  300,    2, 0x08,   51 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   34,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::QString, QMetaType::Int,   39,
    QMetaType::Void,
    0x80000000 | 42,
    QMetaType::Bool, QMetaType::QString,   44,
    QMetaType::Double,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_comboBoxADCRes_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBoxChannel_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateSineWave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EXIT_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_start_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_open_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_delete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'parameters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateRecentOperations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_parameters_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateComPorts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onComboBoxIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'monitorConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTimeLapse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_mode_currentIndexChanged1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_up_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_down_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSerialDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSerialPortError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_comConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_up_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_up_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_down_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_down_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLoadValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateCycleCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getBatchString'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'threadFunc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getCurrentDateAndTime'
        QtPrivate::TypeAndForceComplete<QPair<QString,QString>, std::false_type>,
        // method 'requestPasscode'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateWave'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_comboBox_existingParamSelec_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_existingParamSelec_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_calibra_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_comboBoxADCRes_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_comboBoxChannel_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->updateSineWave(); break;
        case 3: _t->on_EXIT_clicked(); break;
        case 4: _t->on_pushButton_start_clicked(); break;
        case 5: _t->on_pushButton_open_clicked(); break;
        case 6: _t->on_pushButton_stop_clicked(); break;
        case 7: _t->on_pushButton_delete_clicked(); break;
        case 8: _t->parameters((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->updateRecentOperations(); break;
        case 10: _t->on_pushButton_parameters_clicked(); break;
        case 11: _t->on_pushButton_save_clicked(); break;
        case 12: _t->updateComPorts(); break;
        case 13: _t->onComboBoxIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->monitorConnection(); break;
        case 15: _t->updateTimeLapse(); break;
        case 16: _t->on_comboBox_mode_currentIndexChanged1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_pushButton_up_clicked(); break;
        case 18: _t->on_pushButton_down_clicked(); break;
        case 19: _t->onSerialDataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->onSerialPortError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->on_pushButton_comConnect_clicked(); break;
        case 22: _t->on_pushButton_up_pressed(); break;
        case 23: _t->on_pushButton_up_released(); break;
        case 24: _t->on_pushButton_down_pressed(); break;
        case 25: _t->on_pushButton_down_released(); break;
        case 26: _t->on_pushButton_2_clicked(); break;
        case 27: _t->updateLoadValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 28: _t->updateCycleCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: { QString _r = _t->getBatchString((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->threadFunc(); break;
        case 31: { std::pair<QString,QString> _r = _t->getCurrentDateAndTime();
            if (_a[0]) *reinterpret_cast< std::pair<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 32: { bool _r = _t->requestPasscode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: { double _r = _t->updateWave();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->on_comboBox_existingParamSelec_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->on_comboBox_existingParamSelec_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 36: _t->on_pushButton_calibra_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWelcomeDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWelcomeDialogENDCLASS = QtMocHelpers::stringData(
    "WelcomeDialog"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWelcomeDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject WelcomeDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSWelcomeDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWelcomeDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWelcomeDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WelcomeDialog, std::true_type>
    >,
    nullptr
} };

void WelcomeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *WelcomeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WelcomeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWelcomeDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WelcomeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
