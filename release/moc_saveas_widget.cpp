/****************************************************************************
** Meta object code from reading C++ file 'saveas_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../saveas_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'saveas_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeypadButton_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeypadButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeypadButton_t qt_meta_stringdata_KeypadButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KeypadButton"
QT_MOC_LITERAL(1, 13, 11), // "key_pressed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10) // "is_pressed"

    },
    "KeypadButton\0key_pressed\0\0is_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeypadButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Char,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void KeypadButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeypadButton *_t = static_cast<KeypadButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->key_pressed((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 1: _t->is_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KeypadButton::*)(char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeypadButton::key_pressed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KeypadButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_KeypadButton.data,
      qt_meta_data_KeypadButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KeypadButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeypadButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeypadButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int KeypadButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KeypadButton::key_pressed(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SaveAs_Widget_t {
    QByteArrayData data[8];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SaveAs_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SaveAs_Widget_t qt_meta_stringdata_SaveAs_Widget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SaveAs_Widget"
QT_MOC_LITERAL(1, 14, 17), // "set_template_name"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "key_pressed"
QT_MOC_LITERAL(4, 45, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(5, 65, 19), // "on_btnCLEAR_clicked"
QT_MOC_LITERAL(6, 85, 18), // "on_btnSAVE_clicked"
QT_MOC_LITERAL(7, 104, 27) // "on_text_field_returnPressed"

    },
    "SaveAs_Widget\0set_template_name\0\0"
    "key_pressed\0on_btnClose_clicked\0"
    "on_btnCLEAR_clicked\0on_btnSAVE_clicked\0"
    "on_text_field_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaveAs_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   47,    2, 0x0a /* Public */,
       4,    0,   50,    2, 0x08 /* Private */,
       5,    0,   51,    2, 0x08 /* Private */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Char,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SaveAs_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SaveAs_Widget *_t = static_cast<SaveAs_Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_template_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->key_pressed((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->on_btnClose_clicked(); break;
        case 3: _t->on_btnCLEAR_clicked(); break;
        case 4: _t->on_btnSAVE_clicked(); break;
        case 5: _t->on_text_field_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SaveAs_Widget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SaveAs_Widget::set_template_name)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SaveAs_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SaveAs_Widget.data,
      qt_meta_data_SaveAs_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SaveAs_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaveAs_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SaveAs_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SaveAs_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SaveAs_Widget::set_template_name(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
