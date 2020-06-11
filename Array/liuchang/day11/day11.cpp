#include <iostream>

struct Node_ {
    int data;
    Node_ *next;
} Node;

struct LinkedList_ {
    int length;
    Node_ *head;
    Node_ *tail;
} LinkedList;

//设计函数
Node_ *make(int data);

void freeNode(Node_ *node);

void visit(Node_ *node);

LinkedList_ *create();

void append(LinkedList_ *list, int data);

void reverse(LinkedList_ *list);

LinkedList_ *combination(LinkedList_ *list, LinkedList_ *list2);

void print(LinkedList_ *list);

Node_ *get(LinkedList_ *list, int index);

Node_ *removeReciprocal(LinkedList_ *list, int index);

//创建node
Node_ *make(int data) {
    Node_ *node = static_cast<Node_ *>(malloc(sizeof(Node)));
    assert(node != NULL);
    node->next = nullptr;
    node->data = data;
    return node;
}

//释放node资源
void freeNode(Node_ *node) {
    free(node);
    node = NULL;
}

//node节点的打印
void visit(Node_ *node) {
    assert(node != NULL);
    printf("[%p | %d]\n", node, node->data);
}

//创建LinkedList
LinkedList_ *create() {
    LinkedList_ *list = static_cast<LinkedList_ *>(malloc(sizeof(LinkedList)));
    assert(list != NULL);
    list->length = 0;
    list->head = make(0);
    list->tail = make(0);
    list->head->next = list->tail;
    return list;
}

void append(LinkedList_ *list, int data) {
    list->tail->data = data;
    Node_ *node = make(0);
    list->tail->next = node;
    list->tail = node;
    list->length += 1;
}

void appendList(LinkedList_ *listA, LinkedList_ *listB) {
    listA->tail->data = listB->head->next->data;
    listA->tail->next = listB->head->next->next;

}

//反转
void reverse(LinkedList_ *list) {
    Node_ *pre = NULL;
    Node_ *current = list->head;
    Node_ *next = current->next;
    while (current != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = next == NULL ? NULL : next->next;

    }
    Node_ *node = list->head;
    list->head = list->tail;
    list->tail = node;

}

Node_ *get(LinkedList_ *list, int index) {
    Node_ *current = list->head;
    for (int i = 0; i < list->length; ++i) {
        if (i == index) {
            return current;
        } else {
            current = current->next;
        }
    }
}

/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * 解题思路
 * 1、首先创建一个链表
 * 2、将A链表加入 新链表
 * 3、将B链表加入 新链表
 * 4、将新链表的数据进行冒泡排序
 */
LinkedList_ *combination(LinkedList_ *list, LinkedList_ *list2) {
    LinkedList_ *newList = create();
    Node_ *listNode = list->head->next;
    while (listNode != list->tail) {
        append(newList, listNode->data);
        listNode = listNode->next;
    }
    Node_ *list2Node = list2->head->next;
    while (list2Node != list2->tail) {
        append(newList, list2Node->data);
        list2Node = list2Node->next;
    }
    for (int i = 0; i < newList->length; i++) {
        for (int j = 0; j < newList->length - 1; j++) {
            int current = get(newList, j)->data;
            int next = get(newList, j + 1)->data;
            if (current > next) {
                get(newList, j)->data = next;
                get(newList, j + 1)->data = current;
            }
        }
    }
    return newList;

}

/**
 * 实现思路
 * 1、获取正向node 的位置
 * 2、根据循环 获取需要删除的节点与 此节点之前的节点
 * 3、做断链操作，将删除节点与 删除节点之前的节点进行断链，并将删除节点的next 接入 删除节点之前的节点
 * 4、返回删除的节点
 */
Node_ *removeReciprocal(LinkedList_ *list, int index) {
    if (index > list->length) {
        return NULL;
    }
    int positive = (list->length) - index;
    Node_ *p = NULL;
    Node_ *current = list->head->next;
    for (int i = 0; i < positive; i++) {
        p = current;
        current = current->next;

    }
    p->next = current->next;
    return current;
}

LinkedList_ *oddEvenSort(LinkedList_ *list) {
    Node_ *odd = list->head->next;
    Node_ *even = odd->next;
    Node_ *abc = odd;
    Node_ *bcd = even;
    while (odd->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = odd->next;
    }
    while (bcd!=NULL){
        append(list,bcd->data);
        bcd = bcd->next;
    }
    return list;
}

void print(LinkedList_ *list) {
    printf("%d\n", list->length);
    printf("head ===> [%p | %d] ---> \n", list->head, list->head->data);
    Node_ *current = list->head->next;
    while (current != list->tail) {
        printf("current ===> [%p | %d] ---> \n", current, current->data);
        current = current->next;
    }
    printf("tail ===> [%p | %d] ---> \n", list->tail, list->tail->data);

}

int main() {
    LinkedList_ *list = create();
//    print(list);
    append(list, 1);
    append(list, 2);
    append(list, 4);
    append(list, 6);
    append(list, 3);
    append(list, 9);

//    removeReciprocal(list, 3);
    oddEvenSort(list);
    print(list);
//    print(list2);
//    print(list);
//    LinkedList_ *list2 = create();
//    LinkedList_ *list3 = combination(list, list2);
//    print(list3);
    return 0;
}
