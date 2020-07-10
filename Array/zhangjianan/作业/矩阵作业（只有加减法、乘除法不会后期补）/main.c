#include <stdio.h>
#include "matrix.c"

int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int array2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};

int main() {
    Matrix *matrix1 = init_matrix(3, 3);
    Matrix *matrix2 = init_matrix(3, 3);
    Matrix *matrix3 = init_matrix(3, 3);
    value_matrix(matrix1, array1);
    value_matrix(matrix2, array1);
//    add_matrix(matrix3,matrix1,matrix2);//加法
    sub_matrix(matrix3,matrix1,matrix2);//减法


    print_matrix(matrix3);



    free_matrix(matrix3);
    free_matrix(matrix1);
    free_matrix(matrix2);

//    struct ListNode* listNode1=   createListNode(NULL,-10);
//    struct ListNode* listNode2=   createListNode(listNode1,-3);
//    struct ListNode* listNode3=   createListNode(listNode2,0);
//    struct ListNode* listNode4=   createListNode(listNode3,5);
//    struct ListNode* listNode5=   createListNode(listNode4,9);
//    struct  TreeNode* treenode=  sortedListToBST(listNode1);
//    listNode2->next=listNode1;
//    prefacePrintTree(treenode);
//    middlePrintTree(treenode);
//    afterwordPrintTree(treenode);
//    struct ListNode* listNode6= detectCycle(listNode1);
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
