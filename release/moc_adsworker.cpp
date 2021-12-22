/****************************************************************************
** Meta object code from reading C++ file 'adsworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeckhoffADS/adsworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adsworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ADSworker_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ADSworker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ADSworker_t qt_meta_stringdata_ADSworker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ADSworker"
QT_MOC_LITERAL(1, 10, 9), // "updateHMI"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "runningTwinCat"
QT_MOC_LITERAL(4, 36, 7), // "boState"
QT_MOC_LITERAL(5, 44, 13), // "TryConnectADS"
QT_MOC_LITERAL(6, 58, 7), // "resetTC"
QT_MOC_LITERAL(7, 66, 8) // "configTC"

    },
    "ADSworker\0updateHMI\0\0runningTwinCat\0"
    "boState\0TryConnectADS\0resetTC\0configTC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ADSworker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ADSworker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ADSworker *_t = static_cast<ADSworker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateHMI(); break;
        case 1: _t->runningTwinCat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { bool _r = _t->TryConnectADS();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->resetTC(); break;
        case 4: _t->configTC(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ADSworker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ADSworker::updateHMI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ADSworker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ADSworker::runningTwinCat)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ADSworker::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ADSworker.data,
      qt_meta_data_ADSworker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ADSworker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADSworker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ADSworker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ADSworker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ADSworker::updateHMI()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ADSworker::runningTwinCat(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
