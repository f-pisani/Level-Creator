/****************************************************************************
** Meta object code from reading C++ file 'GUI_ToolBox.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI_ToolBox.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_ToolBox.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_ToolBox_t {
    QByteArrayData data[15];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_ToolBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_ToolBox_t qt_meta_stringdata_GUI_ToolBox = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GUI_ToolBox"
QT_MOC_LITERAL(1, 12, 13), // "assetSelected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "std::string"
QT_MOC_LITERAL(4, 39, 11), // "updateLevel"
QT_MOC_LITERAL(5, 51, 5), // "Level"
QT_MOC_LITERAL(6, 57, 5), // "level"
QT_MOC_LITERAL(7, 63, 12), // "updateToolID"
QT_MOC_LITERAL(8, 76, 7), // "Tool_ID"
QT_MOC_LITERAL(9, 84, 4), // "tool"
QT_MOC_LITERAL(10, 89, 17), // "assetsCellClicked"
QT_MOC_LITERAL(11, 107, 10), // "currentRow"
QT_MOC_LITERAL(12, 118, 13), // "currentColumn"
QT_MOC_LITERAL(13, 132, 11), // "previousRow"
QT_MOC_LITERAL(14, 144, 14) // "previousColumn"

    },
    "GUI_ToolBox\0assetSelected\0\0std::string\0"
    "updateLevel\0Level\0level\0updateToolID\0"
    "Tool_ID\0tool\0assetsCellClicked\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_ToolBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
      10,    4,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,

       0        // eod
};

void GUI_ToolBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_ToolBox *_t = static_cast<GUI_ToolBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->assetSelected((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->updateLevel((*reinterpret_cast< Level(*)>(_a[1]))); break;
        case 2: _t->updateToolID((*reinterpret_cast< Tool_ID(*)>(_a[1]))); break;
        case 3: _t->assetsCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI_ToolBox::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_ToolBox::assetSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GUI_ToolBox::staticMetaObject = {
    { &QToolBox::staticMetaObject, qt_meta_stringdata_GUI_ToolBox.data,
      qt_meta_data_GUI_ToolBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI_ToolBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_ToolBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_ToolBox.stringdata0))
        return static_cast<void*>(const_cast< GUI_ToolBox*>(this));
    return QToolBox::qt_metacast(_clname);
}

int GUI_ToolBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GUI_ToolBox::assetSelected(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
