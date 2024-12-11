/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
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
    "sampleName",
    "freq",
    "setPoint",
    "Amplitude",
    "stopCyle",
    "QCompleter*",
    "comp",
    "updateRecentOperations",
    "Operation",
    "operation",
    "on_pushButton_parameters_clicked",
    "on_pushButton_save_clicked",
    "on_pushButton_clicked",
    "updateComPorts",
    "onComboBoxIndexChanged",
    "index",
    "monitorConnection",
    "updateTimeLapse",
    "on_comboBox_mode_currentIndexChanged1",
    "on_pushButton_up_clicked",
    "on_pushButton_down_clicked",
    "onSerialDataReceived",
    "data1",
    "onSerialPortError",
    "error",
    "on_pushButton_comConnect_clicked"
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
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  152,    2, 0x08,    1 /* Private */,
       4,    1,  155,    2, 0x08,    3 /* Private */,
       5,    0,  158,    2, 0x08,    5 /* Private */,
       6,    0,  159,    2, 0x08,    6 /* Private */,
       7,    0,  160,    2, 0x08,    7 /* Private */,
       8,    0,  161,    2, 0x08,    8 /* Private */,
       9,    0,  162,    2, 0x08,    9 /* Private */,
      10,    0,  163,    2, 0x08,   10 /* Private */,
      11,    6,  164,    2, 0x08,   11 /* Private */,
      19,    1,  177,    2, 0x08,   18 /* Private */,
      22,    0,  180,    2, 0x08,   20 /* Private */,
      23,    0,  181,    2, 0x08,   21 /* Private */,
      24,    0,  182,    2, 0x08,   22 /* Private */,
      25,    0,  183,    2, 0x08,   23 /* Private */,
      26,    1,  184,    2, 0x08,   24 /* Private */,
      28,    0,  187,    2, 0x08,   26 /* Private */,
      29,    0,  188,    2, 0x08,   27 /* Private */,
      30,    1,  189,    2, 0x08,   28 /* Private */,
      31,    0,  192,    2, 0x08,   30 /* Private */,
      32,    0,  193,    2, 0x08,   31 /* Private */,
      33,    1,  194,    2, 0x08,   32 /* Private */,
      35,    1,  197,    2, 0x08,   34 /* Private */,
      37,    0,  200,    2, 0x08,   36 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 17,   12,   13,   14,   15,   16,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::QString,   36,
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
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCompleter *, std::false_type>,
        // method 'updateRecentOperations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Operation &, std::false_type>,
        // method 'on_pushButton_parameters_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
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
        case 8: _t->parameters((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QCompleter*>>(_a[6]))); break;
        case 9: _t->updateRecentOperations((*reinterpret_cast< std::add_pointer_t<Operation>>(_a[1]))); break;
        case 10: _t->on_pushButton_parameters_clicked(); break;
        case 11: _t->on_pushButton_save_clicked(); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->updateComPorts(); break;
        case 14: _t->onComboBoxIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->monitorConnection(); break;
        case 16: _t->updateTimeLapse(); break;
        case 17: _t->on_comboBox_mode_currentIndexChanged1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_pushButton_up_clicked(); break;
        case 19: _t->on_pushButton_down_clicked(); break;
        case 20: _t->onSerialDataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->onSerialPortError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->on_pushButton_comConnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 5:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCompleter* >(); break;
            }
            break;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
