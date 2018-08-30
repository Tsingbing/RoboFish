/****************************************************************************
** Meta object code from reading C++ file 'mapwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mapwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mapWidget_t {
    QByteArrayData data[9];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapWidget_t qt_meta_stringdata_mapWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "mapWidget"
QT_MOC_LITERAL(1, 10, 25), // "on_gotoQrigin_Btn_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_showTrack_Btn_clicked"
QT_MOC_LITERAL(4, 62, 10), // "clearRuler"
QT_MOC_LITERAL(5, 73, 10), // "startRuler"
QT_MOC_LITERAL(6, 84, 15), // "acceptFlashData"
QT_MOC_LITERAL(7, 100, 3), // "str"
QT_MOC_LITERAL(8, 104, 15) // "receiveLocation"

    },
    "mapWidget\0on_gotoQrigin_Btn_clicked\0"
    "\0on_showTrack_Btn_clicked\0clearRuler\0"
    "startRuler\0acceptFlashData\0str\0"
    "receiveLocation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    3,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,

       0        // eod
};

void mapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mapWidget *_t = static_cast<mapWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_gotoQrigin_Btn_clicked(); break;
        case 1: _t->on_showTrack_Btn_clicked(); break;
        case 2: _t->clearRuler(); break;
        case 3: _t->startRuler(); break;
        case 4: _t->acceptFlashData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->receiveLocation((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject mapWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mapWidget.data,
      qt_meta_data_mapWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mapWidget.stringdata0))
        return static_cast<void*>(const_cast< mapWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int mapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
