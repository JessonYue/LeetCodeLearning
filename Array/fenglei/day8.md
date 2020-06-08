#### 周末数据结构复习 & 算法

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int data;;

struct Node {
    data value;
    struct Node *next;
};

struct ListNode {
    struct Node *head;
    struct Node *tail;
    int length;
};

// 创建
struct Node *make(int data);

// 释放
void freeNode(struct Node *node);

// 创建链表
struct ListNode *create();

// 销毁链表
void freeList(struct ListNode *list);

// 插入
void insert(int index, int data, struct ListNode *list);

// 追加
void append(int data, struct ListNode *list);

// 删除
void deleteNode(int index, struct ListNode *list);

// 反转
struct ListNode* reverse(struct ListNode *list);

// 打印
void visit(struct Node *node);

// 打印list
void print(struct ListNode *list);

// 测试
void list_test();

struct Node *make(int data) {
    struct Node *node = static_cast<Node *>(malloc(sizeof(struct Node)));;
    assert(node != NULL);
    node->value = data;
    node->next = NULL;
    return node;
}

void freeNode(struct Node *node) {
    free(node);
    node = NULL;
}

struct ListNode *create() {
    struct ListNode *list = static_cast<ListNode *>(malloc(sizeof(struct ListNode)));
    assert(list != NULL);
    list->length = 0;
    list->head = make(0);
    list->tail = make(0);
    list->head->next = list->tail;
    return list;
}

void freeList(struct ListNode *list) {
    struct Node *currentNode = list->head;
    while (currentNode->next != list->tail) {
        struct Node *node = currentNode->next;
        freeNode(currentNode);
        currentNode = node;
    }
    freeNode(list->head);
    freeNode(list->tail);
    free(list);
    list = NULL;
}


void append(int data, struct ListNode *list) {
    list->tail->value = data;
    struct Node *node = make(0);
    list->tail->next = node;
    list->tail = node;
    list->length += 1;
}

void insert(int index, int data, struct ListNode *list) {
    assert(index > 0 && index < list->length);
    unsigned int i = 0;
    struct Node *currentNode = list->head->next;
    while (currentNode != list->tail) {
        if (i == index) {
            struct Node *node = make(data);
            struct Node *nextNode = currentNode->next;
            currentNode->next = node;
            node->next = nextNode;
            list->length += 1;
            return;
        }
        currentNode = currentNode->next;
        i++;
    }
    if (currentNode == list->tail) {
        append(data, list);
    }
}

void deleteNode(int index, struct ListNode *list) {
    assert(index > 0 && index < list->length);
    unsigned int i = 0;
    struct Node *currentNode = list->head->next;
    struct Node *node = NULL;
    while (currentNode != list->tail) {
        if (i == index) {
            node->next = currentNode->next;
            freeNode(currentNode);
            list->length -= 1;
            return;
        }
        node = currentNode;
        currentNode = currentNode->next;
        i++;
    }
}



struct ListNode* reverse(struct ListNode *list) {
    assert(list != NULL);
    if (list->head == list->tail) {
        return list;
    }
    struct Node *leftPointer = NULL;
    struct Node *midPointer = list->head;
    struct Node *rightPointer = midPointer->next;
    while (midPointer !=NULL){
        midPointer->next = leftPointer;
        leftPointer = midPointer;
        midPointer = rightPointer;
        rightPointer = (rightPointer == NULL?NULL:rightPointer->next);
    }
    struct Node* node = list->head;
    list->head = list->tail;
    list->tail = node;
    return list;
}


void visit(struct Node *node) {
    assert(node != NULL);
    printf("[%p | %d]\n", node, node->value);
}

void print(struct ListNode *list) {
    assert(list != NULL);
    printf("==========list ===========\n");
    printf("head[%p | %d]\n", list->head, list->head->value);
    struct Node *current = list->head->next;
    while (current != list->tail) {
        visit(current);
        current = current->next;
    }
    printf("tail[%p | %d]\n", list->tail, list->tail->value);
}

void list_test(){
    struct ListNode* list = create();
    print(list);
    append(100,list);
    append(120,list);
    append(140,list);
    append(160,list);
    append(170,list);
    append(180,list);
    print(list);
    reverse(list);
    print(list);
    deleteNode(2,list);
    print(list);
    insert(1,200,list);
    print(list);
}

int main() {
    list_test();
    return 0;
}
```



#### 算法

```
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 
限制：
0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



##### C

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
         ListNode* leftPointer = NULL;
         ListNode* midPointer = head;
         ListNode* rightPointer = head->next;
        while (midPointer) {
            // 逆序
            midPointer->next = leftPointer;
            // 指针偏移
            leftPointer = midPointer;
            midPointer = rightPointer;
            rightPointer = rightPointer == NULL ? NULL : rightPointer->next;
        }
        return leftPointer;
    }
};
```



