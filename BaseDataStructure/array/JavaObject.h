//
// Created by Jesson on 2020/7/18.
//

#ifndef BASEDATASTRUCTURE_JAVAOBJECT_H
#define BASEDATASTRUCTURE_JAVAOBJECT_H


//定义结构体
typedef struct JavaObject{
    int retainCount;
}JavaObject;

//宏定义方法 方便书写 宏函数
#define OBJRETAIN(obj) objectRetain((JavaObject*)obj)
#define OBJRELEASE(obj) objectRelease((JavaObject*)obj)
#define GETRETAINCOUNT(obj) getRetainCount((JavaObject*)obj)

void objectRetain(JavaObject *obj);
void objectRelease(JavaObject *obj);
int getRetainCount(JavaObject *obj);

#endif //BASEDATASTRUCTURE_JAVAOBJECT_H
