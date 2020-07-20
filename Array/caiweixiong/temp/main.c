
#include <stdio.h>
#include "array/Array.h"
#include "array/Person.h"

int main() {
    Array *array = newArray();
    addElement(array, (Object) newPerson(newString("test01"), newInteger(1)));
    addElement(array, (Object) newPerson(newString("test02"), newInteger(2)));
    addElement(array, (Object) newPerson(newString("test03"), newInteger(3)));
    addElement(array, (Object) newPerson(newString("test04"), newInteger(4)));
    addElement(array, (Object) newPerson(newString("test05"), newInteger(5)));
    addElement(array, (Object) newPerson(newString("test06"), newInteger(6)));
    addElement(array, (Object) newPerson(newString("test07"), newInteger(7)));
    addElement(array, (Object) newPerson(newString("test08"), newInteger(8)));
    addElement(array, (Object) newPerson(newString("test09"), newInteger(9)));
    addElement(array, (Object) newPerson(newString("test10"), newInteger(10)));

    printArray(array);

    insertIndexAt(array, (Object) newPerson(newString("test11"), newInteger(11)), 4);
    printArray(array);

    // 释放部分资源
    Person *person = (Person *) getObjectIndexAt(array, 10);
    printf("the person name : %s, age : %d\n", getStringValue(person->name), getIntegerValue(person->age));
    // 回收对象
    personRelease(person);
    removeIndexAt(array, 10);
    printArray(array);
    
    // 释放剩余的资源
    for (int i = array->length - 1; i >= 0; --i) {
        personRelease((Person *) getObjectIndexAt(array, i));
        removeIndexAt(array, i);
    }
    
    destroyArray(array);
    
    return 0;
}
