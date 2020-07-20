//
// Created by Vashon on 2020/7/20.
//

#ifndef BASEDATASTRUCT_STRING_H
#define BASEDATASTRUCT_STRING_H

#include "JavaObject.h"

typedef struct String {
    int retainCount;
    char *value;
} String;

String *newString(char *value);

char *getStringValue(String *string);

#endif //BASEDATASTRUCT_STRING_H
