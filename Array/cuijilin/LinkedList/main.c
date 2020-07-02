#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"
#include "linked_stack.h"

Node *createNode(data value) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void *freeNode(Node *node) {
    assert(node);
    free(node);
    node = NULL;
}

void *isLinkedListEmpty(LinkedList *linkedList) {
    assert(NULL != linkedList);
}

LinkedList *createLinkedList() {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    isLinkedListEmpty(linkedList);
    linkedList->head = NULL;
    linkedList->length = 0;
    return linkedList;
}

void appendLinkedList(LinkedList *linkedList, data value) {
    isLinkedListEmpty(linkedList);
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
    if (index < 0) {
        printf("error:invalid index");
        return;
    }
    Node *head = createNode(-1);
    head->next = linkedList->head;
    Node *current = head->next;
    assert(current);
    Node *pre = head;
    int count = 0;

    while (NULL != current) {
        if (index == count) {
            break;
        }
        pre = current;
        current = current->next;
        count++;
    }
    if (head == pre) {
        linkedList->head = current->next;
    } else {
        pre->next = current->next;
        freeNode(current);
    }

    freeNode(head);

    linkedList->length -= 1;

    if (count < index) {
        printf("error:out of bounds");
    }

}

void removeNthFromEnd(LinkedList *linkedList, data n) {
    assert(linkedList);
    assert(linkedList->head);

    Node *pre = linkedList->head;
    Node *current = pre;


}

void reverseLinkedList(LinkedList *linkedList) {
    isLinkedListEmpty(linkedList);
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
//    isLinkedListEmpty(linkedList);
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

Node *getMidNode(LinkedList *linkedList) {
    assert(linkedList);
    Node *slow = linkedList->head;
    assert(slow);
    Node *fast = slow;
    Node *mid = NULL;
    assert(fast);
    for (;;) {
        if (NULL == fast->next) { //odd
            mid = slow;
            break;
        } else if (NULL == fast->next->next) { // even
            printf("error:even list!!\n");
            return FALSE;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return mid;
}

int isPalindrome(LinkedList *linkedList) {
    assert(linkedList);
    Node *mid = getMidNode(linkedList);
    printf("The Middle Node ==> %d\n", mid->value);
    // reverse
    Node *pre = NULL;
    Node *current = mid->next;
    Node *temp = pre;
    while (NULL != current) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }

    Node *head = NULL;
    if (NULL != pre) {
        head = pre;
    }
    printLinkedList(head);

    Node *rightCur = head;
    Node *leftCur = linkedList->head;
    while (NULL != rightCur) {
        if (leftCur->value != rightCur->value) {
            return FALSE;
        }
        leftCur = leftCur->next;
        rightCur = rightCur->next;
    }

    return TRUE;
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
    appendLinkedList(linkedList, 1);
    appendLinkedList(linkedList, 2);
    appendLinkedList(linkedList, 3);
    appendLinkedList(linkedList, 4);
    appendLinkedList(linkedList, 5);
//    appendLinkedList(linkedList, 4);
//    appendLinkedList(linkedList, 3);
//    appendLinkedList(linkedList, 2);
//    appendLinkedList(linkedList, 1);
    printLinkedList(linkedList->head);

    deleteNodeByIndex(linkedList, 4);
    printLinkedList(linkedList->head);

//    reverseLinkedList(linkedList);
//    printLinkedList(linkedList);

//    oddEvenList(linkedList);
//    printLinkedList(linkedList);

//    LinkedList *list2 = createLinkedList();
//    appendLinkedList(list2, 3);
//    appendLinkedList(list2, 4);
//    appendLinkedList(list2, 8);
//    appendLinkedList(list2, 9);
//
//    Node *mNode = mergeTwoLists(linkedList->head, list2->head);
//    printLinkedList(mNode);

//    printf("The LinkedList Is Palindrome ? %s", isPalindrome(linkedList) == TRUE ? "TRUE" : "FALSE");


}


// stack
Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}


ListStackNode *push(Stack *stack, int value) {
    assert(stack);
    ListStackNode *top = stack->top;
    ListStackNode *current = malloc(sizeof(ListStackNode));
    assert(current);
    current->value = value;
    current->next = top;
    stack->top = current;
    printf("push:%d\n", value);
    return top;
}

ListStackNode *pop(Stack *stack) {
    assert(stack);
    ListStackNode *top = (ListStackNode *) stack->top;
    ListStackNode *temp = top->next;
    stack->top = temp;
    free(temp);
    printf("pop:%d\n", stack->top->value);
    return stack->top;
}

void *release(Stack *stack) {
    assert(stack);
    ListStackNode *node = stack->top;
    ListStackNode *temp = NULL;
    while (NULL != node) {
        temp = node;
        free(temp);
        node = node->next;
    }
    free(stack);

}


void *printStack(Stack *stack) {
    assert(stack);
    ListStackNode *head = stack->top;
    ListStackNode *current = head;
    while (NULL != current) {
        printf("node==>%d\n", current->value);
        current = current->next;
    }
}


void *test_stack() {
    Stack *stack = createStack();
    ListStackNode *current = NULL;
    int size = 6, element;
    int counter = 0;

//    while (counter < size) {
//        scanf("%d", &element);
//        current = push(stack,element);
//        counter++;
//    }
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    pop(stack);
//    pop(stack);
//    release(stack);
    printStack(stack);
}


int main() {
//    test_list();
    test_stack();
    return 0;
}



