/****************************************************************************
** Meta object code from reading C++ file 'ImplantDesign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ImplantDesign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImplantDesign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImplantDesign_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImplantDesign_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImplantDesign_t qt_meta_stringdata_ImplantDesign = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ImplantDesign"
QT_MOC_LITERAL(1, 14, 13), // "OnDeleteModel"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 23), // "ModelControlWidgetItem*"
QT_MOC_LITERAL(4, 53, 4), // "item"
QT_MOC_LITERAL(5, 58, 13), // "OnOpenProject"
QT_MOC_LITERAL(6, 72, 15), // "OnContourChoose"
QT_MOC_LITERAL(7, 88, 14), // "OnSingleChoose"
QT_MOC_LITERAL(8, 103, 14) // "OnCloseContour"

    },
    "ImplantDesign\0OnDeleteModel\0\0"
    "ModelControlWidgetItem*\0item\0OnOpenProject\0"
    "OnContourChoose\0OnSingleChoose\0"
    "OnCloseContour"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImplantDesign[] = {

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
       1,    1,   39,    2, 0x09 /* Protected */,
       5,    0,   42,    2, 0x09 /* Protected */,
       6,    0,   43,    2, 0x09 /* Protected */,
       7,    0,   44,    2, 0x09 /* Protected */,
       8,    0,   45,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImplantDesign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImplantDesign *_t = static_cast<ImplantDesign *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnDeleteModel((*reinterpret_cast< ModelControlWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->OnOpenProject(); break;
        case 2: _t->OnContourChoose(); break;
        case 3: _t->OnSingleChoose(); break;
        case 4: _t->OnCloseContour(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModelControlWidgetItem* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ImplantDesign::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImplantDesign.data,
      qt_meta_data_ImplantDesign,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImplantDesign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImplantDesign::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImplantDesign.stringdata0))
        return static_cast<void*>(const_cast< ImplantDesign*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImplantDesign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
