//
// Created by Vashon on 2020/7/21.
//

#ifndef BASEDATASTRUCT_PERSON_H
#define BASEDATASTRUCT_PERSON_H

#include "Integer.h"
#include "String.h"

typedef struct Person {
    int retainCount;
    String *name;
    Integer *age;
} Person;

Person *newPerson(String *name, Integer *age);

String *getPersonName(Person *person);

Integer *getPersonAge(Person *person);

void printPerson(Person *person);

void releasePerson(Person *person);

#endif //BASEDATASTRUCT_PERSON_H
