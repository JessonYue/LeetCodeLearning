//
// Created by Vashon on 2020/7/20.
//

#include <stdlib.h>
#include <assert.h>
#include "Person.h"

Person *newPerson(String *name, Integer *age) {
    Person *person = malloc(sizeof(Person));
    assert(person != NULL);
    person->retainCount = 0;
    person->name = name;
    person->age = age;
    OBJ_RETAIN(person);
    return person;
}

String *getName(Person *person) {
    return person->name;
}

Integer *getAge(Person *person) {
    return person->age;
}
