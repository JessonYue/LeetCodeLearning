//
// Created by Vashon on 2020/7/21.
//

#include "Integer.h"

Integer *newInteger(int value) {
    Integer *integer = malloc(sizeof(Integer));
    assert(integer != NULL);
    integer->retainCount = 0;
    integer->value = value;
    OBJ_RETAIN(integer);
    return integer;
}

int getIntegerValue(Integer *integer) {
    return integer->value;
}