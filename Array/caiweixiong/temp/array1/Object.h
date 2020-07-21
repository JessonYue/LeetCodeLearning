//
// Created by Vashon on 2020/7/21.
//

#ifndef BASEDATASTRUCT_OBJECT_H
#define BASEDATASTRUCT_OBJECT_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define OBJ_RETAIN(object) objectRetain((Object *)object)
#define OBJ_RELEASE(object) objectRelease((Object *)object)

typedef struct Object {
    int retainCount;    // 引用计数，用于释放资源
} Object;

// 获取对象的引用计数
int getObjectRetainCount(Object *object);

// 对象被引用
void objectRetain(Object *object);

// 对象被释放
void objectRelease(Object *object);

#endif //BASEDATASTRUCT_OBJECT_H
