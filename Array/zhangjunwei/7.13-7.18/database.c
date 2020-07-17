//
// Created by 张俊伟 on 2020/7/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 假如数据库中有如下记录：
 * 43 peter        21 Linda        90 Jesson        77 Donald
 * 编写代码完成：
 * 1）从文件中读取Person对象
 * 2）讲Person写入一个新文件
 * 3）对Person根据姓名排序
 * 4）释放内存
 * 5）关闭文件流
 */
typedef struct person {
    int age;
    char name[20];
} Person;

int compareperson(const void *p1, const void *p2) {
    const Person *person1 = (const Person *) p1;
    const Person *person2 = (const Person *) p2;
    if (person1->age > person2->age)
        return 1;
    if (person1->age < person2->age)
        return -1;
    return 0;
}

int main() {
    char *file_in = "/Users/zhangjunwei/Desktop/tmp/licodecpp17/july/data";
    char *file_out = "/Users/zhangjunwei/Desktop/tmp/licodecpp17/july/data1";
    FILE *fptr;
    fptr = fopen(file_in, "r");
    if (fptr == NULL) {
        printf("open file failed");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    while ((read = getline(&line, &len, fptr)) != -1) {
//        printf("Retrieved line of length %zu :\n", read);
//        printf("%s", line);
        count++;
    }
    printf("\n");
    Person *arr_person = (Person *) malloc(sizeof(Person) * count);
    if (arr_person == NULL) {
        printf("calloc person failed");
        fclose(fptr);
        return EXIT_FAILURE;
    } else {
        memset(arr_person, 0, sizeof(Person) * count);
    }
    fseek(fptr, 0, SEEK_SET);
    char *age = NULL;
    Person *pcur = arr_person;

    while (!feof(fptr)) {
        fscanf(fptr, "%d %s", &pcur->age, pcur->name);
        pcur++;
    }
    fclose(fptr);
    fptr = NULL;

    printf("-----------------------------\n");
    pcur = arr_person;
    for (int i = 0; i < count; ++i) {
        printf("%d\n", pcur->age);
        printf("%s\n", pcur->name);
        pcur++;
    }
    printf("-----------------------------\n");

    pcur = arr_person;
    qsort(arr_person, count, sizeof(Person), compareperson);

    for (int i = 0; i < count; ++i) {
        printf("%d\n", (*pcur).age);
        printf("%s\n", (*pcur).name);
        pcur++;
    }
    fptr = fopen(file_out, "w");
    if (fptr == NULL) {
        printf("open file write failed");
        return EXIT_FAILURE;
    }
    pcur = arr_person;
    for (int i = 0; i < count; ++i) {
        fprintf(fptr, "%d %s\n", pcur->age, pcur->name);
        pcur++;
    }
    fclose(fptr);
    fptr = NULL;
    return EXIT_SUCCESS;
}