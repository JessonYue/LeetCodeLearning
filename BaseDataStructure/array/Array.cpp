//
// Created by Jesson on 2020/7/18.
//

#include "Array.h"
#include "People.h"
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <cstring>

//分配空间
static AnyObject* allocMemoryByCapacity(Array *arr){
    return static_cast<AnyObject *>(malloc(sizeof(AnyObject) * arr->capacity));
}

//创建数组
Array* newArray(){
    Array *arr = static_cast<Array *>(malloc(sizeof(Array)));
    arr->length = 0;
    arr->capacity = 32;
    arr->value = allocMemoryByCapacity(arr);
    return arr;
}

//获取数组长度
int getArrayLength(Array *array){
    return array->length;
}

//增加元素
void addElement(Array *array,AnyObject value){
    if (array->length >= array->capacity) {
        array->capacity *= 2;
        AnyObject *oldValue = array->value;
        memcpy(array->value, oldValue, array->length*sizeof(AnyObject));
        free(oldValue);
    }
    OBJRETAIN(value);
    array->value[array->length] = value;
    array->length++;
}

//删除元素
Array* removeIndexAt(Array *arry,int index){
    assert(index >= 0 && index < arry->length);  //断言 防止越界

    OBJRELEASE(getValueIndexAt(arry, index));

    arry->length -- ;
    for (int i = index-1; i < arry->length; i++) {
        arry->value[i] = arry->value[i+1];
    }
    return arry;
}

//在指定位置增加元素
Array* insertIndexAt(Array *array,AnyObject value,int index){
    if (array->length >= array->capacity) {
        array->capacity *= 2;
        AnyObject *oldValue = array->value;
        memcpy(array->value, oldValue, array->length*sizeof(AnyObject));
        free(oldValue);
    }
    array->length++;

    //插入指定位置
    array->value[index-1] = value;
    //将元素后移
    for (int i = index; i < array->length; i++) {
        array->value[array->length] = array->value[array->length-i];
    }
    OBJRETAIN(value);
    return array;
}



//获取某个元素
AnyObject getValueIndexAt(Array *array,int index){
    assert(index >= 0 && index < array->length);
    return array->value[index];
}

//销毁
void destroyArray(Array *array){
    free(array->value);
    free(array);
    printf("数组被销毁\n");
}
//打印结果
void printArray(Array *arr){
    for (int i = 0; i < arr->length; i++) {
        printf("位置:%d,姓名:%s,年龄:%d\n",i, getStringValue(getName((People*)getValueIndexAt(arr, i))),getIntegerValue(getAge((People*)getValueIndexAt(arr, i))));
    }
}

int main(){
    Array *arr = newArray();

    People *p0 = newPeople(newString("A"), newInteger(20));
    People *p1 = newPeople(newString("B"), newInteger(16));
    People *p2 = newPeople(newString("C"), newInteger(17));
    People *p3 = newPeople(newString("D"), newInteger(14));
    People *p4 = newPeople(newString("E"), newInteger(22));
    People *p5 = newPeople(newString("F"), newInteger(18));
    People *p6 = newPeople(newString("G"), newInteger(25));
    People *p7 = newPeople(newString("H"), newInteger(11));
    People *p8 = newPeople(newString("I"), newInteger(19));
    People *p9 = newPeople(newString("K"), newInteger(22));
    People *p10 = newPeople(newString("P"), newInteger(23));



    //增加元素
    addElement(arr, (JavaObject *)p0);
    addElement(arr, (JavaObject *)p1);
    addElement(arr, (JavaObject *)p2);
    addElement(arr, (JavaObject *)p3);
    addElement(arr, (JavaObject *)p4);
    addElement(arr, (JavaObject *)p5);
    addElement(arr, (JavaObject *)p6);
    addElement(arr, (JavaObject *)p7);
    addElement(arr, (JavaObject *)p8);
    addElement(arr, (JavaObject *)p9);


    //释放内存
    OBJRELEASE((JavaObject*) p0);
    OBJRELEASE((JavaObject*) p1);
    OBJRELEASE((JavaObject*) p2);
    OBJRELEASE((JavaObject*) p3);
    OBJRELEASE((JavaObject*) p4);
    OBJRELEASE((JavaObject*) p5);
    OBJRELEASE((JavaObject*) p6);
    OBJRELEASE((JavaObject*) p7);
    OBJRELEASE((JavaObject*) p8);
    OBJRELEASE((JavaObject*) p9);


    printf("增加10个元素\n");
    printArray(arr);

    printf("删除第3个元素\n");
    //删除第数组中某一个元素
    removeIndexAt(arr, 3);
    printArray(arr);

    printf("插入P10成为第4个元素\n");
    //插入
    insertIndexAt(arr, (JavaObject *)p10, 4);
    printArray(arr);

    OBJRELEASE((JavaObject*) p10);

    printf("查找第5个元素\n");
    //index从0开始 查找第5个元素 index=4
    printf("位置:%d,姓名:%s,年龄:%d\n",4,
            getStringValue(getName((People*)getValueIndexAt(arr, 4))),
            getIntegerValue(getAge((People*)getValueIndexAt(arr, 4))));

    //销毁数组
    destroyArray(arr);
}