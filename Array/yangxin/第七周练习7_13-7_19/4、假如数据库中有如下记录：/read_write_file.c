#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 * 4、假如数据库中有如下记录：
       43 peter
       21 Linda
       90 Jesson
       77 Donald
       ......
编写代码完成：1）从文件中读取Person对象2）讲Person写入一个新文件3）对Person根据姓名排序4）释放内存5）关闭文件流
 */
//从文件中读取Person对象
typedef struct {
    int id;
    char name[8];
} Person;

int getPersonCount(FILE *file) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, 0);
    return size / sizeof(Person);
}

Person *initPerson(int id, char *name) {
    Person *person = malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    return person;
}

Person *loadPerson(FILE *file, int *count) {
    size_t p_size = sizeof(Person);
    *count = getPersonCount(file);

    Person *array = malloc(p_size * (*count));
    int r;
    r = fread(array, p_size, *count, file);
    if (r != 0) {
        return array;
    } else {
        return NULL;
    }
}

int writePerson(FILE *file, Person *person) {
    return fwrite(person, sizeof(Person), 1, file);
}

//交换排序
void sortByName(Person *person, int count) {
    int tmp;
    Person tmp_person;
    int size = sizeof(Person);
    for (int i = 0, count_i = count - 1; i < count_i; i++) {
        tmp = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(person[tmp].name, person[j].name) > 0) {
                tmp = j;
            }
        }
        memcpy(&tmp_person, &person[tmp], size);
        memcpy(&person[tmp], &person[i], size);
        memcpy(&person[i], &tmp_person, size);
    }
}

void main() {
//    printf("%s\n", str_copy("hello world!"));
//    printf("%s\n", link_str("hello 12 ", "world!"));
//    printf("%d\n", str_chr("hello world!", 'h'));
//    char *s = malloc(sizeof(char) * 6);
//    printf("%s\n", str_memcpy(s, "hello", 5));

//写入数据
//    FILE *file = fopen("C:/Users/12/Desktop/test123.db", "rt+");
//    printf("%d\n", writePerson(file, initPerson(1, "test1")));
//    printf("%d\n", writePerson(file, initPerson(2, "test2")));
//    printf("%d\n", writePerson(file, initPerson(43, "peter")));
//    printf("%d\n", writePerson(file, initPerson(21, "Linda")));
//    printf("%d\n", writePerson(file, initPerson(90, "Jesson")));
//    printf("%d\n", writePerson(file, initPerson(77, "Donald")));
//    int count;
//    Person *array = loadPerson(file, &count);
//    for (int i = 0; i < count; i++) {
//        printf("%d->%s\n", array[i].id, array[i].name);
//    }
//
//    fclose(file);

    //读取全部数据，并打印
    FILE *read_file = fopen("C:/Users/12/Desktop/test.db", "r+");
    int count;
    Person *array = loadPerson(read_file, &count);
    for (int i = 0; i < count; i++) {
        printf("%d->%s\n", array[i].id, array[i].name);
    }

    //写入新文件
//    FILE *write_file = fopen("C:/Users/12/Desktop/new_test.db", "w+");
//    for (int i = 0; i < count; i++) {
//        writePerson(read_file, initPerson(array[i].id, array[i].name));
//    }
//    fclose(write_file);

    //排序
    sortByName(array, count);
    printf("After sorted:\n");
    for (int i = 0; i < count; i++) {
        printf("%d->%s\n", array[i].id, array[i].name);
    }

    free(array);
    fclose(read_file);
}