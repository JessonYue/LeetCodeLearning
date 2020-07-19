#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 数据库中有如下记录：
 * 43 peter
 * 21 Linda
 * 90 Jesson
 * 77 Donald
 * ......
 * 编写代码完成：
 * 1）从文件中读取Person对象
 * 2）讲Person写入一个新文件
 * 3）对Person根据姓名排序
 * 4）释放内存
 * 5）关闭文件流
 */

typedef struct Person {
    int age;
    char name[30];
} Person;

int compare(const void *p1, const void *p2) {
    const Person *person1 = (const Person *) p1;
    const Person *person2 = (const Person *) p2;
    if (person1->age > person2->age)
        return 1;
    if (person1->age < person2->age)
        return -1;
    return 0;
}

int main() {
    char *file_source = "/Users/zhanchengguo/Desktop/db";
    char *file_target = "/Users/zhanchengguo/Desktop/db1";
    FILE *file;

    //打开文件进行读取
    file = fopen(file_source, "r");
    if (file == NULL) {
        printf("open file failed\n");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    //读取文件中的每一行，获取有多少行数据
    while ((read = getline(&line, &len, file)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        count++;
    }
    printf("\n");

    //初始化存储数组
    Person *person_arr = malloc(sizeof(Person) * count);
    memset(person_arr, 0, sizeof(Person) * count);

    //读取文件内容到本地Person数组中
    fseek(file, 0, SEEK_SET);
    Person *currPerson = person_arr;
    while (!feof(file)) {
        fscanf(file, "%d %s", &currPerson->age, currPerson->name);
        currPerson++;
    }
    fclose(file);
    file = NULL;

    printf("-------------打印原始信息----------------\n");
    currPerson = person_arr;
    for (int i = 0; i < count; ++i) {
        printf("%d   %s\n", currPerson->age, currPerson->name);
        currPerson++;
    }

    //排序
    currPerson = person_arr;
    qsort(person_arr, count, sizeof(Person), compare);

    printf("-------------打印排序后信息----------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%d   %s\n", currPerson->age, currPerson->name);
        currPerson++;
    }

    //写文件
    file = fopen(file_target, "w");
    if (file == NULL) {
        printf("open file failed\n");
        return -1;
    }

    currPerson = person_arr;
    for (int i = 0; i < count; ++i) {
        fprintf(file_target, "%d %s\n", currPerson->age, currPerson->name);
        currPerson++;
    }
    fclose(file);
    file = NULL;

    return 0;
}