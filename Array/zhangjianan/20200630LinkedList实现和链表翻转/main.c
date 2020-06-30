#include <stdio.h>
#include "maxProfit.c"
#include "MyNode.c"


int main() {
    struct LinkedList *list = creatLinkedList();
    insertLinkedList(list, 1);
    insertLinkedList(list, 2);
    insertLinkedList(list, 3);
    insertLinkedList(list, 4);
    insertLinkedList(list, 5);
    reverseLinkedList(list);
//    print(list);
//    deleteLinkedListByIndex(list, 2);
    printLinkedList(list);
    free_(list);
    return 0;
}
