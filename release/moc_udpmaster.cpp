/****************************************************************************
** Meta object code from reading C++ file 'udpmaster.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../udpmaster.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpmaster.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UdpMaster_t {
    QByteArrayData data[33];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UdpMaster_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UdpMaster_t qt_meta_stringdata_UdpMaster = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UdpMaster"
QT_MOC_LITERAL(1, 10, 14), // "sendReciveData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "sendSendData"
QT_MOC_LITERAL(4, 39, 14), // "sendSensorData"
QT_MOC_LITERAL(5, 54, 23), // "receiveMessageFromSlave"
QT_MOC_LITERAL(6, 78, 21), // "sendLightCommandToUdp"
QT_MOC_LITERAL(7, 100, 5), // "light"
QT_MOC_LITERAL(8, 106, 23), // "sendPanTileCommandToUdp"
QT_MOC_LITERAL(9, 130, 7), // "panTilt"
QT_MOC_LITERAL(10, 138, 11), // "sendZoomOut"
QT_MOC_LITERAL(11, 150, 20), // "sendMoveCommandToUDP"
QT_MOC_LITERAL(12, 171, 5), // "axisX"
QT_MOC_LITERAL(13, 177, 5), // "axisY"
QT_MOC_LITERAL(14, 183, 5), // "axisR"
QT_MOC_LITERAL(15, 189, 5), // "axisU"
QT_MOC_LITERAL(16, 195, 1), // "b"
QT_MOC_LITERAL(17, 197, 22), // "sendSetMotorParameters"
QT_MOC_LITERAL(18, 220, 2), // "LF"
QT_MOC_LITERAL(19, 223, 2), // "LB"
QT_MOC_LITERAL(20, 226, 2), // "RF"
QT_MOC_LITERAL(21, 229, 2), // "RB"
QT_MOC_LITERAL(22, 232, 20), // "sendSetPIDParameters"
QT_MOC_LITERAL(23, 253, 4), // "mode"
QT_MOC_LITERAL(24, 258, 1), // "P"
QT_MOC_LITERAL(25, 260, 1), // "I"
QT_MOC_LITERAL(26, 262, 1), // "D"
QT_MOC_LITERAL(27, 264, 15), // "sendMachineHand"
QT_MOC_LITERAL(28, 280, 2), // "qi"
QT_MOC_LITERAL(29, 283, 7), // "sendGPS"
QT_MOC_LITERAL(30, 291, 6), // "longit"
QT_MOC_LITERAL(31, 298, 5), // "latit"
QT_MOC_LITERAL(32, 304, 15) // "sendSelfBalance"

    },
    "UdpMaster\0sendReciveData\0\0sendSendData\0"
    "sendSensorData\0receiveMessageFromSlave\0"
    "sendLightCommandToUdp\0light\0"
    "sendPanTileCommandToUdp\0panTilt\0"
    "sendZoomOut\0sendMoveCommandToUDP\0axisX\0"
    "axisY\0axisR\0axisU\0b\0sendSetMotorParameters\0"
    "LF\0LB\0RF\0RB\0sendSetPIDParameters\0mode\0"
    "P\0I\0D\0sendMachineHand\0qi\0sendGPS\0"
    "longit\0latit\0sendSelfBalance"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpMaster[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    7,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  100,    2, 0x0a /* Public */,
       6,    1,  101,    2, 0x0a /* Public */,
       8,    1,  104,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    5,  108,    2, 0x0a /* Public */,
      17,    4,  119,    2, 0x0a /* Public */,
      22,    4,  128,    2, 0x0a /* Public */,
      27,    1,  137,    2, 0x0a /* Public */,
      29,    2,  140,    2, 0x0a /* Public */,
      32,    2,  145,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar,    7,
    QMetaType::Void, QMetaType::SChar,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::SChar,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::SChar, QMetaType::Float, QMetaType::Float, QMetaType::Float,   23,   24,   25,   26,
    QMetaType::Void, QMetaType::SChar,   28,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   30,   31,
    QMetaType::Void, QMetaType::SChar, QMetaType::Bool,   28,   16,

       0        // eod
};

void UdpMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpMaster *_t = static_cast<UdpMaster *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendReciveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendSendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendSensorData((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7]))); break;
        case 3: _t->receiveMessageFromSlave(); break;
        case 4: _t->sendLightCommandToUdp((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 5: _t->sendPanTileCommandToUdp((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 6: _t->sendZoomOut(); break;
        case 7: _t->sendMoveCommandToUDP((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5]))); break;
        case 8: _t->sendSetMotorParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4]))); break;
        case 9: _t->sendSetPIDParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 10: _t->sendMachineHand((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 11: _t->sendGPS((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 12: _t->sendSelfBalance((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpMaster::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpMaster::sendReciveData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UdpMaster::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpMaster::sendSendData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UdpMaster::*_t)(float , float , float , float , float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpMaster::sendSensorData)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject UdpMaster::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UdpMaster.data,
      qt_meta_data_UdpMaster,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UdpMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UdpMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UdpMaster.stringdata0))
        return static_cast<void*>(const_cast< UdpMaster*>(this));
    return QObject::qt_metacast(_clname);
}

int UdpMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void UdpMaster::sendReciveData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UdpMaster::sendSendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UdpMaster::sendSensorData(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
