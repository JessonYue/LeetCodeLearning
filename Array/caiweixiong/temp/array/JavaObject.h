//
// Created by Vashon on 2020/7/20.
//

#ifndef BASEDATASTRUCT_JAVAOBJECT_H
#define BASEDATASTRUCT_JAVAOBJECT_H

typedef struct JavaObject {
    int retainCount;
} JavaObject;

#define OBJ_RETAIN(obj) objectRetain((JavaObject *)obj)
#define OBJ_RELEASE(obj) objectRelease((JavaObject *)obj)
#define GET_RETAIN_COUNT(obj) getRetainCount((JavaObject *)obj)

// 记录对象引用计数
void objectRetain(JavaObject *obj);

// 释放对象引用
void objectRelease(JavaObject *obj);

// 获取当前的对象引用计数
int getRetainCount(JavaObject *obj);

#endif //BASEDATASTRUCT_JAVAOBJECT_H
