//
// Created by Jesson on 2020/7/18.
//

//#include <malloc.h>
#include <cstdlib>
#include "Integer.h"
#include "JavaObject.h"

Integer *newInteger(int value) {
    Integer *newInteger = static_cast<Integer *>(malloc(sizeof(Integer)));
    OBJRETAIN(newInteger);
    newInteger->value = value;
    return newInteger;
}

int getIntegerValue(Integer* ins) {
    return ins->value;
}