/****************************************************************************
** Meta object code from reading C++ file 'my_scene.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isiviewer_glut/my_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,
      44,   41,    8,    8, 0x05,
      78,   71,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,    9,    8,    8, 0x0a,
     129,   41,    8,    8, 0x0a,
     153,   71,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyScene[] = {
    "MyScene\0\0co\0sigCurrentObjectChanged(int)\0"
    "dm\0sigDisplayModeChanged(int)\0radius\0"
    "sigRadiusChanged(double)\0"
    "slotSetCurrentObject(int)\0"
    "slotSetDisplayMode(int)\0slotSetRadius(double)\0"
};

void MyScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyScene *_t = static_cast<MyScene *>(_o);
        switch (_id) {
        case 0: _t->sigCurrentObjectChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigDisplayModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->slotSetCurrentObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotSetDisplayMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotSetRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyScene::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyScene,
      qt_meta_data_MyScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyScene))
        return static_cast<void*>(const_cast< MyScene*>(this));
    return QObject::qt_metacast(_clname);
}

int MyScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyScene::sigCurrentObjectChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyScene::sigDisplayModeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyScene::sigRadiusChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
