//
// Created by Vashon on 2020/7/21.
//

#include "String.h"

String *newString(char *value) {
    String *string = malloc(sizeof(String));
    assert(string != NULL);
    string->retainCount = 0;
    string->value = value;
    OBJ_RETAIN(string);
    return string;
}

char *getStringValue(String *string) {
    return string->value;
}