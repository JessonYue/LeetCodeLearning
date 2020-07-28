//
// Created by Jesson on 2020/7/18.
//

#include <cstdio>
//#include <malloc.h>
#include <cstdlib>
#include "JavaObject.h"

void objectRetain(JavaObject *obj) {

    obj->retainCount ++;
    printf("retain计数+1 = %d\n",obj->retainCount);

}

void objectRelease(JavaObject *obj) {
    obj->retainCount --;
    if (obj->retainCount <= 0) {
        free(obj);
    }
    printf("retain计数-1 = %d\n",obj->retainCount);

}
//获得当前计数
int getRetainCount(JavaObject *obj) {
    return obj->retainCount;
}