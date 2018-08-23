/****************************************************************************
** Meta object code from reading C++ file 'GUI_AssetsManager.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI_AssetsManager.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_AssetsManager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_AssetsManager_t {
    QByteArrayData data[16];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_AssetsManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_AssetsManager_t qt_meta_stringdata_GUI_AssetsManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GUI_AssetsManager"
QT_MOC_LITERAL(1, 18, 34), // "on_listWidget_itemSelectionCh..."
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 25), // "on_listWidget_itemEntered"
QT_MOC_LITERAL(4, 80, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 97, 4), // "item"
QT_MOC_LITERAL(6, 102, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(7, 128, 26), // "on_selectAllButton_clicked"
QT_MOC_LITERAL(8, 155, 28), // "on_unselectAllButton_clicked"
QT_MOC_LITERAL(9, 184, 32), // "on_toggleSelectionButton_clicked"
QT_MOC_LITERAL(10, 217, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(11, 238, 23), // "on_renameButton_clicked"
QT_MOC_LITERAL(12, 262, 23), // "on_removeButton_clicked"
QT_MOC_LITERAL(13, 286, 26), // "on_removeAllButton_clicked"
QT_MOC_LITERAL(14, 313, 26), // "on_exportDatButton_clicked"
QT_MOC_LITERAL(15, 340, 26) // "on_importDatButton_clicked"

    },
    "GUI_AssetsManager\0on_listWidget_itemSelectionChanged\0"
    "\0on_listWidget_itemEntered\0QListWidgetItem*\0"
    "item\0on_listWidget_itemClicked\0"
    "on_selectAllButton_clicked\0"
    "on_unselectAllButton_clicked\0"
    "on_toggleSelectionButton_clicked\0"
    "on_addButton_clicked\0on_renameButton_clicked\0"
    "on_removeButton_clicked\0"
    "on_removeAllButton_clicked\0"
    "on_exportDatButton_clicked\0"
    "on_importDatButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_AssetsManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI_AssetsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_AssetsManager *_t = static_cast<GUI_AssetsManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listWidget_itemSelectionChanged(); break;
        case 1: _t->on_listWidget_itemEntered((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_selectAllButton_clicked(); break;
        case 4: _t->on_unselectAllButton_clicked(); break;
        case 5: _t->on_toggleSelectionButton_clicked(); break;
        case 6: _t->on_addButton_clicked(); break;
        case 7: _t->on_renameButton_clicked(); break;
        case 8: _t->on_removeButton_clicked(); break;
        case 9: _t->on_removeAllButton_clicked(); break;
        case 10: _t->on_exportDatButton_clicked(); break;
        case 11: _t->on_importDatButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GUI_AssetsManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GUI_AssetsManager.data,
      qt_meta_data_GUI_AssetsManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI_AssetsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_AssetsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_AssetsManager.stringdata0))
        return static_cast<void*>(const_cast< GUI_AssetsManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int GUI_AssetsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
