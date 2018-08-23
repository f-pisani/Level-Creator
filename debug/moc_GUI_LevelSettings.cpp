/****************************************************************************
** Meta object code from reading C++ file 'GUI_LevelSettings.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI_LevelSettings.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_LevelSettings.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_LevelSettings_t {
    QByteArrayData data[7];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_LevelSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_LevelSettings_t qt_meta_stringdata_GUI_LevelSettings = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GUI_LevelSettings"
QT_MOC_LITERAL(1, 18, 31), // "on_confirmation_Button_accepted"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 31), // "on_confirmation_Button_rejected"
QT_MOC_LITERAL(4, 83, 24), // "on_selectPathBtn_clicked"
QT_MOC_LITERAL(5, 108, 37), // "on_levelWidth_spinBox_editing..."
QT_MOC_LITERAL(6, 146, 38) // "on_levelHeight_spinBox_editin..."

    },
    "GUI_LevelSettings\0on_confirmation_Button_accepted\0"
    "\0on_confirmation_Button_rejected\0"
    "on_selectPathBtn_clicked\0"
    "on_levelWidth_spinBox_editingFinished\0"
    "on_levelHeight_spinBox_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_LevelSettings[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI_LevelSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_LevelSettings *_t = static_cast<GUI_LevelSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_confirmation_Button_accepted(); break;
        case 1: _t->on_confirmation_Button_rejected(); break;
        case 2: _t->on_selectPathBtn_clicked(); break;
        case 3: _t->on_levelWidth_spinBox_editingFinished(); break;
        case 4: _t->on_levelHeight_spinBox_editingFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GUI_LevelSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GUI_LevelSettings.data,
      qt_meta_data_GUI_LevelSettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI_LevelSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_LevelSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_LevelSettings.stringdata0))
        return static_cast<void*>(const_cast< GUI_LevelSettings*>(this));
    if (!strcmp(_clname, "Ui::GUI_LevelSettings"))
        return static_cast< Ui::GUI_LevelSettings*>(const_cast< GUI_LevelSettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int GUI_LevelSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
