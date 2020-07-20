
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
    // Person内的String与Integer也是malloc出来的，所以也要进行计数减少并释放
    OBJ_RELEASE((Object) person->name);
    OBJ_RELEASE((Object) person->age);
    // 由于Add与Inset的时候进行了retain，所以这里应该要手动减少1次计数，不然无法释放
    OBJ_RELEASE((Object) person);
    removeIndexAt(array, 10);
    printArray(array);

    // 释放剩余的资源
    for (int i = array->length - 1; i >= 0; --i) {
        Person *p = (Person *) getObjectIndexAt(array, i);
        OBJ_RELEASE((Object) p->name);
        OBJ_RELEASE((Object) p->age);
        OBJ_RELEASE((Object) p);
        removeIndexAt(array, i);
    }

    destroyArray(array);

    return 0;
}
