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
            if (current> next) {
                get(newList, j)->data = next;
                get(newList, j+1)->data = current;
            }
        }
    }
    return newList;

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
//    print(list);
    LinkedList_ *list2 = create();
    append(list2, 1);
    append(list2, 3);
    append(list2, 4);
//    print(list2);
    LinkedList_ *list3 = combination(list, list2);
    print(list3);
    return 0;
}
