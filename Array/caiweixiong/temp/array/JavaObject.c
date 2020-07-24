//
// Created by Vashon on 2020/7/20.
//

#include "JavaObject.h"
#include <stdio.h>
#include <stdlib.h>

void objectRetain(JavaObject *obj) {
    obj->retainCount++;
    printf("obj retain count add : %d\n", obj->retainCount);
}

void objectRelease(JavaObject *obj) {
    obj->retainCount--;
    printf("obj retain count sub : %d\n", obj->retainCount);
    if (obj->retainCount <= 0)
        free(obj);
}

int getRetainCount(JavaObject *obj) {
    return obj->retainCount;
}
