//
// Created by Jesson on 2020/7/18.
//

//#include <malloc.h>
#include <cstdlib>
#include "String.h"

String* newString(char* value){
    String *str = static_cast<String *>(malloc(sizeof(String)));
    OBJRETAIN(str);
    str->value = value;
    return str;

}

char* getStringValue(String* ins){
    return ins->value;
}