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

void print(LinkedList_ *list);

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

//工具类


int main() {
    LinkedList_ *list = create();
    print(list);
    append(list, 1001);
    append(list, 1002);
    append(list, 1003);
    append(list, 1004);
    print(list);
    reverse(list);
    print(list);
    return 0;
}
