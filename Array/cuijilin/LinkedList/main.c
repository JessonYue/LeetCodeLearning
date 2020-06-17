#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

Node *createNode(data value) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void *isEmpty(LinkedList *linkedList) {
    assert(NULL != linkedList);
}

LinkedList *createLinkedList() {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    isEmpty(linkedList);
    linkedList->head = NULL;
    linkedList->length = 0;
    return linkedList;
}

void appendLinkedList(LinkedList *linkedList, data value) {
    isEmpty(linkedList);
    Node *current = linkedList->head;
    Node *tail = NULL;
    if (NULL == current) {
        linkedList->head = createNode(value);
        linkedList->head->next = NULL;
        linkedList->length = 1;
        return;
    }

    while (current != NULL) {
        tail = current;
        current = current->next;
    }

    if (NULL == current) {
        tail->next = createNode(value);
        tail->next->next = NULL;
        linkedList->length = linkedList->length + 1;
    }

}

void deleteNodeByIndex(LinkedList *linkedList, int index) {
    assert(linkedList);
    Node *current = linkedList->head;
    assert(current);
    Node *pre = NULL;
    int count = 0;
    while (NULL != current) {
        if (index == count++) {
            if (NULL == pre) {
                linkedList->head = linkedList->head->next;
            } else {
                pre->next = current->next;
            }
            linkedList->length--;
        }
        pre = current;
        current = current->next;
    }

    if (count <= index) {
        printf("error:out of bounds");
    }


}

void reverseLinkedList(LinkedList *linkedList) {
    isEmpty(linkedList);
    Node *current = NULL;
    current = linkedList->head;
    Node *pre = NULL;
    Node *temp = NULL;
    while (NULL != current) {
        temp = current->next;// 步骤1：
        current->next = pre;//步骤2：
        pre = current;// 步骤3：
        current = temp;// 步骤4：
    }
    // 1，3，4是遍历，2是原地翻转

    if (pre != NULL) {
        linkedList->head = pre;
    }
}

Node *getIntersectionNode(Node *headA, Node *headB) {

}

Node *mergeTwoLists(Node *n1, Node *n2) {
    // 递归
    if (NULL == n1) {
        return n2;
    }
    if (NULL == n2) {
        return n1;
    }

    if (n1->value < n2->value) {
        n1->next = mergeTwoLists(n1->next, n2);
        return n1;
    } else {
        n2->next = mergeTwoLists(n1, n2->next);
        return n2;
    }

/**  迭代法*/
//    Node *head = createNode(-1);
//    Node *current = head;
//    while (NULL != n1 && NULL != n2) {
//        if (n1->value < n2->value) {
//            current->next = n1;
//            n1 = n1->next;
//        } else {
//            current->next = n2;
//            n2 = n2->next;
//        }
//        current = current->next;
//    }
//    if (NULL == n1) {
//        current->next = n2;
//    } else {
//        current->next = n1;
//    }
//    return head->next;
}

Node *oddEvenList(LinkedList *linkedList) {
//    isEmpty(linkedList);
    Node *head = linkedList->head;
//    assert(head);
    Node *oddHead = head;
    Node *odd = head;
    Node *evenHead = head->next;
    Node *evenTail = evenHead;
    assert(evenTail);

    while (NULL != evenTail && NULL != evenTail->next) {
        odd->next = evenTail->next;
        odd = odd->next;
        evenTail->next = odd->next;
        evenTail = evenTail->next;
    }
    odd->next = evenHead;
    return head;
}

int isPalindrome(LinkedList *linkedList) {

    return FALSE;
}

void printLinkedList(Node *head) {
    Node *current = head;
    printf("**************** print linkedList ****************\n");
    while (NULL != current) {
        printf("node==>[%p | %d]--->\n", current, current->value);
        current = current->next;
    }
    printf("***************************************************\n");
}

void test_list() {
    LinkedList *linkedList = createLinkedList();
    appendLinkedList(linkedList, 11);
    appendLinkedList(linkedList, 22);
    appendLinkedList(linkedList, 33);
    appendLinkedList(linkedList, 44);
    appendLinkedList(linkedList, 55);
    appendLinkedList(linkedList, 66);
    printLinkedList(linkedList->head);

//    deleteNodeByIndex(linkedList, 0);
//    printLinkedList(linkedList->head);

//    reverseLinkedList(linkedList);
//    printLinkedList(linkedList);

//    oddEvenList(linkedList);
//    printLinkedList(linkedList);

    LinkedList *list2 = createLinkedList();
    appendLinkedList(list2, 3);
    appendLinkedList(list2, 4);
    appendLinkedList(list2, 8);
    appendLinkedList(list2, 9);

    Node *mNode = mergeTwoLists(linkedList->head, list2->head);
    printLinkedList(mNode);


}

int main() {
    test_list();
    return 0;
}



