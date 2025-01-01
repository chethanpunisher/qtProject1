/****************************************************************************
** Meta object code from reading C++ file 'analysisplot.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../analysisplot.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysisplot.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAnalysisPlotENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAnalysisPlotENDCLASS = QtMocHelpers::stringData(
    "AnalysisPlot",
    "loadComboBox",
    "",
    "populateComboBoxWithExcelFiles",
    "folderPath",
    "listSamplesByAscendingIndex",
    "QList<QJsonObject>",
    "JsonManager&",
    "jsonManager4",
    "startLoading",
    "filePath",
    "updateProgress",
    "value",
    "onDataLoaded",
    "QList<QPointF>",
    "data",
    "yMin",
    "yMax",
    "moveLeft",
    "moveRight",
    "on_moveRightButton_clicked",
    "on_moveLeftButton_clicked",
    "on_comboBox_sampleSelec_currentTextChanged",
    "arg1",
    "on_comboBox_batchSelec_currentTextChanged",
    "timerUpdate",
    "on_moveLeftButton_pressed",
    "on_moveRightButton_pressed",
    "on_moveLeftButton_released",
    "on_moveRightButton_released",
    "stopMovement"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAnalysisPlotENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x08,    1 /* Private */,
       3,    1,  123,    2, 0x08,    2 /* Private */,
       5,    1,  126,    2, 0x08,    4 /* Private */,
       9,    1,  129,    2, 0x08,    6 /* Private */,
      11,    1,  132,    2, 0x08,    8 /* Private */,
      13,    3,  135,    2, 0x08,   10 /* Private */,
      18,    0,  142,    2, 0x08,   14 /* Private */,
      19,    0,  143,    2, 0x08,   15 /* Private */,
      20,    0,  144,    2, 0x08,   16 /* Private */,
      21,    0,  145,    2, 0x08,   17 /* Private */,
      22,    1,  146,    2, 0x08,   18 /* Private */,
      24,    1,  149,    2, 0x08,   20 /* Private */,
      25,    0,  152,    2, 0x08,   22 /* Private */,
      26,    0,  153,    2, 0x08,   23 /* Private */,
      27,    0,  154,    2, 0x08,   24 /* Private */,
      28,    0,  155,    2, 0x08,   25 /* Private */,
      29,    0,  156,    2, 0x08,   26 /* Private */,
      30,    0,  157,    2, 0x08,   27 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    0x80000000 | 6, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QReal, QMetaType::QReal,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AnalysisPlot::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSAnalysisPlotENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAnalysisPlotENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAnalysisPlotENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AnalysisPlot, std::true_type>,
        // method 'loadComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'populateComboBoxWithExcelFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'listSamplesByAscendingIndex'
        QtPrivate::TypeAndForceComplete<QList<QJsonObject>, std::false_type>,
        QtPrivate::TypeAndForceComplete<JsonManager &, std::false_type>,
        // method 'startLoading'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onDataLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QPointF>, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'moveLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveRightButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveLeftButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_sampleSelec_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_batchSelec_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'timerUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveLeftButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveRightButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveLeftButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveRightButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopMovement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AnalysisPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnalysisPlot *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadComboBox(); break;
        case 1: _t->populateComboBoxWithExcelFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { QList<QJsonObject> _r = _t->listSamplesByAscendingIndex((*reinterpret_cast< std::add_pointer_t<JsonManager&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QJsonObject>*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->startLoading((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onDataLoaded((*reinterpret_cast< std::add_pointer_t<QList<QPointF>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 6: _t->moveLeft(); break;
        case 7: _t->moveRight(); break;
        case 8: _t->on_moveRightButton_clicked(); break;
        case 9: _t->on_moveLeftButton_clicked(); break;
        case 10: _t->on_comboBox_sampleSelec_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->on_comboBox_batchSelec_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->timerUpdate(); break;
        case 13: _t->on_moveLeftButton_pressed(); break;
        case 14: _t->on_moveRightButton_pressed(); break;
        case 15: _t->on_moveLeftButton_released(); break;
        case 16: _t->on_moveRightButton_released(); break;
        case 17: _t->stopMovement(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPointF> >(); break;
            }
            break;
        }
    }
}

const QMetaObject *AnalysisPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalysisPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAnalysisPlotENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AnalysisPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSExcelLoader2ENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSExcelLoader2ENDCLASS = QtMocHelpers::stringData(
    "ExcelLoader2",
    "progressUpdated",
    "",
    "value",
    "dataLoaded",
    "QList<QPointF>",
    "data",
    "yMin",
    "yMax",
    "finished",
    "load"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSExcelLoader2ENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    3,   41,    2, 0x06,    3 /* Public */,
       9,    0,   48,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   49,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QReal, QMetaType::QReal,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ExcelLoader2::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSExcelLoader2ENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSExcelLoader2ENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSExcelLoader2ENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExcelLoader2, std::true_type>,
        // method 'progressUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dataLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QPointF>, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ExcelLoader2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExcelLoader2 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->dataLoaded((*reinterpret_cast< std::add_pointer_t<QList<QPointF>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 2: _t->finished(); break;
        case 3: _t->load(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPointF> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExcelLoader2::*)(int );
            if (_t _q_method = &ExcelLoader2::progressUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExcelLoader2::*)(QVector<QPointF> , qreal , qreal );
            if (_t _q_method = &ExcelLoader2::dataLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ExcelLoader2::*)();
            if (_t _q_method = &ExcelLoader2::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ExcelLoader2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExcelLoader2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSExcelLoader2ENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ExcelLoader2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ExcelLoader2::progressUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExcelLoader2::dataLoaded(QVector<QPointF> _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExcelLoader2::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
