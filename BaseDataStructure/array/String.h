//
// Created by Jesson on 2020/7/18.
//

#ifndef BASEDATASTRUCTURE_STRING_H
#define BASEDATASTRUCTURE_STRING_H
#include "JavaObject.h"

typedef struct String{
    int retainCount;
    char *value;
}String;

String* newString(char* value);

char* getStringValue(String* ins);

#endif //BASEDATASTRUCTURE_STRING_H
