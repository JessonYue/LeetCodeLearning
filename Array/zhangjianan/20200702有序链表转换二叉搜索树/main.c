#include <stdio.h>
#include "maxProfit.c"
#include "MyNode.c"
#include "SortedListToBST.c"


int main() {
    struct ListNode* listNode1=   createListNode(NULL,-10);
    struct ListNode* listNode2=   createListNode(listNode1,-3);
    struct ListNode* listNode3=   createListNode(listNode2,0);
    struct ListNode* listNode4=   createListNode(listNode3,5);
    struct ListNode* listNode5=   createListNode(listNode4,9);
    struct  TreeNode* treenode=  sortedListToBST(listNode1);
//    prefacePrintTree(treenode);
//    middlePrintTree(treenode);
//    afterwordPrintTree(treenode);

//    struct LinkedList *list = creatLinkedList();
//    insertLinkedList(list, 1);
//    insertLinkedList(list, 2);
//    insertLinkedList(list, 3);
//    insertLinkedList(list, 4);
//    insertLinkedList(list, 5);
//    kthToLast(list,2);
//    reverseLinkedList(list);
//    print(list);
//    deleteLinkedListByIndex(list, 2);
//    printLinkedList(list);
//    free_(list);
    return 0;
}
