/****************************************************************************
** Meta object code from reading C++ file 'GUI_StatusBar.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI_StatusBar.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_StatusBar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_StatusBar_t {
    QByteArrayData data[12];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_StatusBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_StatusBar_t qt_meta_stringdata_GUI_StatusBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GUI_StatusBar"
QT_MOC_LITERAL(1, 14, 9), // "updateFPS"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "fps"
QT_MOC_LITERAL(4, 29, 10), // "updateTool"
QT_MOC_LITERAL(5, 40, 9), // "tool_name"
QT_MOC_LITERAL(6, 50, 18), // "updateViewPosition"
QT_MOC_LITERAL(7, 69, 1), // "x"
QT_MOC_LITERAL(8, 71, 1), // "y"
QT_MOC_LITERAL(9, 73, 14), // "updateViewZoom"
QT_MOC_LITERAL(10, 88, 4), // "zoom"
QT_MOC_LITERAL(11, 93, 10) // "updateCell"

    },
    "GUI_StatusBar\0updateFPS\0\0fps\0updateTool\0"
    "tool_name\0updateViewPosition\0x\0y\0"
    "updateViewZoom\0zoom\0updateCell"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_StatusBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       6,    2,   45,    2, 0x08 /* Private */,
       9,    1,   50,    2, 0x08 /* Private */,
      11,    2,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::UInt,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void GUI_StatusBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_StatusBar *_t = static_cast<GUI_StatusBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateFPS((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->updateTool((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateViewPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->updateViewZoom((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->updateCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject GUI_StatusBar::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_GUI_StatusBar.data,
      qt_meta_data_GUI_StatusBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI_StatusBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_StatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_StatusBar.stringdata0))
        return static_cast<void*>(const_cast< GUI_StatusBar*>(this));
    return QStatusBar::qt_metacast(_clname);
}

int GUI_StatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
