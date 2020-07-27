//
// Created by Vashon on 2020/7/21.
//

#include "Object.h"

int getObjectRetainCount(Object *object) {
    return object->retainCount;
}

void objectRetain(Object *object) {
    object->retainCount++;
    printf("Object retain add : %d\n", getObjectRetainCount(object));
}

void objectRelease(Object *object) {
    object->retainCount--;
    printf("Object retain sub : %d\n", getObjectRetainCount(object));
    if (!getObjectRetainCount(object)) {    // 当引用计数变为 0，释放资源
        free(object);
        printf("Object free completed\n");
    }
}
