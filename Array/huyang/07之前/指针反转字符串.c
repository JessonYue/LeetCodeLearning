#include <stdio.h>

void swap(char *head, char *tail) {
    char t;
    while(head<tail)
    {

        printf("%p   %p \n",head, tail);
        t=*head;
        *head=*tail;
        *tail=t;
        head++;
        tail--;
    }
}

int main(void) {
    char a[] = "i love china";
    char *b = a;
    char *c = a;
    int size = sizeof(a) / sizeof(char);
    while ((*c) != '\0') {
        c++;
    }
    --c;
    swap(b, c);
    printf("%s",b);
}

