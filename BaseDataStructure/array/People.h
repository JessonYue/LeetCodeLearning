//
// Created by Jesson on 2020/7/18.
//

#ifndef BASEDATASTRUCTURE_PEOPLE_H
#define BASEDATASTRUCTURE_PEOPLE_H
#include "JavaObject.h"
#include "String.h"
#include "Integer.h"

typedef struct People{
    int retainCount;
    String* name;
    Integer* age;

}People;

People* newPeople(String *name,Integer *age);
String* getName(People* people);
Integer* getAge(People* people);

#endif //BASEDATASTRUCTURE_PEOPLE_H
