
#include <stdio.h>

//#include "array/Array.h"
//#include "array/Person.h"

#include "array1/Array.h"
#include "array1/Person.h"

int main() {
//    Array *array = newArray();
//    ADD_ELEM(array, newPerson(newString("test01"), newInteger(1)));
//    ADD_ELEM(array, newPerson(newString("test02"), newInteger(2)));
//    ADD_ELEM(array, newPerson(newString("test03"), newInteger(3)));
//    ADD_ELEM(array, newPerson(newString("test04"), newInteger(4)));
//    ADD_ELEM(array, newPerson(newString("test05"), newInteger(5)));
//    ADD_ELEM(array, newPerson(newString("test06"), newInteger(6)));
//    ADD_ELEM(array, newPerson(newString("test07"), newInteger(7)));
//    ADD_ELEM(array, newPerson(newString("test08"), newInteger(8)));
//    ADD_ELEM(array, newPerson(newString("test09"), newInteger(9)));
//    ADD_ELEM(array, newPerson(newString("test10"), newInteger(10)));
//
//    for (int j = 0; j < getArrayLength(array); ++j) {
//        printPerson((Person *) getObjectIndexAt(array, j));
//    }
//
//    insertIndexAt(array, (Object) newPerson(newString("test11"), newInteger(11)), 4);
//
//    for (int j = 0; j < getArrayLength(array); ++j) {
//        printPerson((Person *) getObjectIndexAt(array, j));
//    }
//
//    // 释放部分资源
//    Person *person = (Person *) getObjectIndexAt(array, 10);
//    personRelease(person);
//    removeIndexAt(array, 10);
//    for (int j = 0; j < getArrayLength(array); ++j) {
//        printPerson((Person *) getObjectIndexAt(array, j));
//    }
//
//    // 释放剩余的资源
//    for (int i = getArrayLength(array) - 1; i >= 0; --i) {
//        personRelease((Person *) getObjectIndexAt(array, i));
//        removeIndexAt(array, i);
//    }
//
//    destroyArray(array);

    Array *array = newArray();
    ADD_ELEM(array, newPerson(newString("test00"), newInteger(0)));
    ADD_ELEM(array, newPerson(newString("test01"), newInteger(1)));
    ADD_ELEM(array, newPerson(newString("test02"), newInteger(2)));
    ADD_ELEM(array, newPerson(newString("test03"), newInteger(3)));
    ADD_ELEM(array, newPerson(newString("test04"), newInteger(4)));
    ADD_ELEM(array, newPerson(newString("test05"), newInteger(5)));
    ADD_ELEM(array, newPerson(newString("test06"), newInteger(6)));
    ADD_ELEM(array, newPerson(newString("test07"), newInteger(7)));
    ADD_ELEM(array, newPerson(newString("test08"), newInteger(8)));
    ADD_ELEM(array, newPerson(newString("test09"), newInteger(9)));

    void (*callback)() = printPerson;
    // 输出数组信息
    printArray(array, callback);
    callback = releasePerson;
    // 回收所有资源
    removeAll(array, callback);
    // 释放数组
    destroyArray(array);

    return 0;
}
