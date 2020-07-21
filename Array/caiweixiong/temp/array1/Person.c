//
// Created by Vashon on 2020/7/21.
//

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

String *getPersonName(Person *person) {
    return person->name;
}

Integer *getPersonAge(Person *person) {
    return person->age;
}

void printPerson(Person *person) {
    printf("the person name is : %s, the person age is : %d\n", getStringValue(getPersonName(person)), getIntegerValue(getPersonAge(person)));
}

void releasePerson(Person *person) {
    // Person内的String与Integer也是malloc出来的，所以也要进行计数减少并释放
    OBJ_RELEASE(person->name);
    OBJ_RELEASE(person->age);
    // 由于Add与Inset的时候进行了retain，所以这里应该要手动减少1次计数，不然无法释放
    OBJ_RELEASE(person);
}