
#include <stdio.h>

//#include "array/Array.h"
//#include "array/Person.h"

#include "array1/Array.h"
#include "array1/Person.h"

// 通过字符串名进行排序
void sortNameByArray(Array *array);

// 对文件进行写数据
void writeMessageToFile(FILE *file, Array *array);

int main() {
    // 测试 array 文件夹的程序
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

    // 测试 array1 文件夹的程序
//    Array *array = newArray();
//    ADD_ELEM(array, newPerson(newString("test00"), newInteger(0)));
//    ADD_ELEM(array, newPerson(newString("test01"), newInteger(1)));
//    ADD_ELEM(array, newPerson(newString("test02"), newInteger(2)));
//    ADD_ELEM(array, newPerson(newString("test03"), newInteger(3)));
//    ADD_ELEM(array, newPerson(newString("test04"), newInteger(4)));
//    ADD_ELEM(array, newPerson(newString("test05"), newInteger(5)));
//    ADD_ELEM(array, newPerson(newString("test06"), newInteger(6)));
//    ADD_ELEM(array, newPerson(newString("test07"), newInteger(7)));
//    ADD_ELEM(array, newPerson(newString("test08"), newInteger(8)));
//    ADD_ELEM(array, newPerson(newString("test09"), newInteger(9)));
//
//    void (*callback)() = printPerson;
//    // 输出数组信息
//    printArray(array, callback);
//    callback = releasePerson;
//    // 回收所有资源
//    removeAll(array, callback);
//    // 释放数组
//    destroyArray(array);

    // 完成作业
    // 1）从文件中读取Person对象
    // 2）对Person根据姓名排序
    // 3）将Person写入一个新文件
    // 4）释放内存
    // 5）关闭文件流

    // 创建数组，保存对象的信息
    Array *array = newArray();
    ADD_ELEM(array, newPerson(newString("peter"), newInteger(43)));
    ADD_ELEM(array, newPerson(newString("Linda"), newInteger(21)));
    ADD_ELEM(array, newPerson(newString("Jesson"), newInteger(90)));
    ADD_ELEM(array, newPerson(newString("Donald"), newInteger(77)));
    // 函数指针，默认指向输出对象的函数起始地址
    void (*callback)() = printPerson;
    // 输出数组信息
    printArray(array, callback);

    // 文件读写开始
    char *filePath1 = "E:\\workspace\\c\\basedatastruct\\test1.txt";
    char *filePath2 = "E:\\workspace\\c\\basedatastruct\\test2.txt";
    FILE *file1 = NULL, *file2 = NULL;
    // 创建文件并写入数据
    file1 = fopen(filePath1, "w+");
    if (file1) {
        writeMessageToFile(file1, array);
        // 改变函数指针的指向
        callback = releasePerson;
        // 回收所有资源
        removeAll(array, callback);
        // 写文件操作完成，开始读，并写到另外一个文件
        file2 = fopen(filePath2, "w+");
        if (file2) {
            rewind(file1);
            rewind(file2);
            char name[64];  // 名字最长不超过64个字符
            int age = 0;
            while (1) {
                fscanf(file1, "%d %s", &age, name);
                if (feof(file1))    // 这里必须这么写，读后再判断，不然会导致多存一次
                    break;
                // 将读出来的数据存放在数组内
                ADD_ELEM(array, newPerson(newString(name), newInteger(age)));
            }
            // 改变函数指针的指向
            callback = printPerson;
            // 输出数组信息
            printArray(array, callback);
            // 写入文件前，进行名称排序
            sortNameByArray(array);
            writeMessageToFile(file2, array);
            // 释放文件描述符
            fclose(file2);
            file2 = NULL;
        } else {
            printf("Create file2 fail\n");
        }
        // 释放文件描述符
        fclose(file1);
        file1 = NULL;
    } else {
        printf("Create file1 fail\n");
    }

    // 改变函数指针的指向
    callback = releasePerson;
    // 回收所有资源
    removeAll(array, callback);
    // 释放数组
    destroyArray(array);

    return 0;
}

void sortNameByArray(Array *array) {
    int arrayLength = getArrayLength(array) - 1;
    for (int i = 0, j = i; i < arrayLength; j = ++i) {
        Person *p1 = (Person *)getElement(array, i + 1);
        Person *p2 = (Person *)getElement(array, j);
        while (strcmp(getPersonNameValue(p1), getPersonNameValue(p2)) < 0) {    // 字符串比较函数，若串 1 小于 串 2
            array->objects[j + 1] = array->objects[j];
            if (j-- == 0)
                break;
        }
        array->objects[j + 1] = (Object *)p1;
    }
}

void writeMessageToFile(FILE *file, Array *array) {
    rewind(file);
    for (int i = 0; i < getArrayLength(array); ++i) {
        Person *person = (Person *) getElement(array, i);
        fprintf(file, "%d %s\n", getPersonAgeValue(person), getPersonNameValue(person));
    }
}





















