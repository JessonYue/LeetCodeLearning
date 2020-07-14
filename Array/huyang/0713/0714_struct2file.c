//
// Created by 胡扬 on 2020/7/14.
//
#include <stdbool.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"

#define  FILE_NAME  "../读写struct/struct2file.dat"
#define  BUFFSIZE  1024     // 缓冲区大小

struct Person{
    char name[100];
    int age;
} ;

void quickSort(struct Person * a, int l,int r){

    if(l>=r)
        return;

    int i = l; int j = r; int key = a[l].age;//选择第一个数为key

    while(i<j){

        while(i<j && a[j].age>=key)//从右向左找第一个小于key的值
            j--;
        if(i<j){
            a[i] = a[j];
            i++;
        }

        while(i<j && a[i].age<key)//从左向右找第一个大于key的值
            i++;

        if(i<j){
            a[j] = a[i];
            j--;
        }
    }
    //i == j
    a[i].age = key;
    quickSort(a, l, i-1);//递归调用
    quickSort(a, i+1, r);//递归调用

}




void readStruct() {
    FILE *pFile;
    struct Person* p = malloc(sizeof(struct Person) * 3);

    pFile = fopen(FILE_NAME, "rb");
    if (pFile == NULL) {
        printf("error open");
        exit(0);
    }

    fread(p, sizeof(struct Person), 3, pFile);

    quickSort(p,0,2);

    printf("%s : %d\n", p[0].name,  p[0].age);
    printf("%s : %d\n", p[1].name,  p[1].age);
    printf("%s : %d\n", p[2].name,  p[2].age);


//    while (fread(p, sizeof(struct Person), 1, pFile) == 1)
//    {
//        printf("%s : %d\n", p->name, p->age);
//        p++;
//    }
    fclose(pFile);
    p = NULL;
    free(p);
}

void writeStruct(){
    FILE *pFile;
    struct Person linda;
    linda.age = 13;
    strcpy(linda.name, "linda");
   struct Person peter;
    peter.age = 14;
    strcpy(peter.name, "peter");
   struct Person donlad;
    donlad.age = 16;
    strcpy(donlad.name, "donlad");

    struct Person su[3] = {linda,peter,donlad};

    pFile = fopen(FILE_NAME, "wb");
    if (pFile == NULL) {
        printf("error open");
        exit(0);
    }

    fwrite(su, sizeof(struct Person), 3, pFile);
    fclose(pFile);

}

void main(){
    writeStruct();
    readStruct();
    return;
}