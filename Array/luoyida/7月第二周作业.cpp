//
// Created by xing on 2020/7/7.
//

#include <cstdio>
#include <queue>

void swap(char *string, char *c);

int main() {
    int n = 23;
    int count = 0;
    while (n > 0) {
        //要消除整数n最低位的1，可以使用 n = n & (n-1)。
        n = n & (n - 1);
        count++;
    }
    printf("%d", count);

    char a[] = "Hello World";
    char *b = a;
    char *c = a;
    while ((*c) != '\0') {
        c++;
    }
    swap(b, --c);
    printf("%s", b);
}

void swap(char *head, char *tail) {
    char t;//临时变量
    while (head < tail) {
        printf("%p   %p \n", head, tail);
        t = *head;
        *head = *tail;
        *tail = t;
        head++;
        tail--;
    }
}


