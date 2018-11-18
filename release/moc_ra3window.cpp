/****************************************************************************
** Meta object code from reading C++ file 'ra3window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ra3window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ra3window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ra3Window_t {
    QByteArrayData data[13];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ra3Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ra3Window_t qt_meta_stringdata_Ra3Window = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Ra3Window"
QT_MOC_LITERAL(1, 10, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 57, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 81, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(6, 105, 11), // "changeEvent"
QT_MOC_LITERAL(7, 117, 7), // "QEvent*"
QT_MOC_LITERAL(8, 125, 1), // "e"
QT_MOC_LITERAL(9, 127, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(10, 151, 5), // "index"
QT_MOC_LITERAL(11, 157, 13), // "retranslateUi"
QT_MOC_LITERAL(12, 171, 12) // "QMainWindow*"

    },
    "Ra3Window\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0changeEvent\0"
    "QEvent*\0e\0on_comboBox_2_activated\0"
    "index\0retranslateUi\0QMainWindow*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ra3Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      11,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,    0,

       0        // eod
};

void Ra3Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ra3Window *_t = static_cast<Ra3Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_2_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->retranslateUi((*reinterpret_cast< QMainWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMainWindow* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Ra3Window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Ra3Window.data,
      qt_meta_data_Ra3Window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ra3Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ra3Window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ra3Window.stringdata0))
        return static_cast<void*>(const_cast< Ra3Window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Ra3Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
