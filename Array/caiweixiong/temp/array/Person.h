//
// Created by Vashon on 2020/7/20.
//

#ifndef BASEDATASTRUCT_PERSON_H
#define BASEDATASTRUCT_PERSON_H

#include "String.h"
#include "Integer.h"

typedef struct Person {
    int retainCount;
    String *name;
    Integer *age;
} Person;

Person *newPerson(String *name, Integer *age);

String *getName(Person *person);

Integer *getAge(Person *person);

#endif //BASEDATASTRUCT_PERSON_H
