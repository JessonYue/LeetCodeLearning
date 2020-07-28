//
// Created by Jesson on 2020/7/18.
//

//#include <malloc.h>
#include <cstdlib>
#include "People.h"

People* newPeople(String *name,Integer *age){
    People *people = static_cast<People *>(malloc(sizeof(People)));
    OBJRETAIN(people);
    people->age = age;
    people->name = name;
    return people;
}
String* getName(People* people){
    return people->name;
}
Integer* getAge(People* people){
    return people->age;
}