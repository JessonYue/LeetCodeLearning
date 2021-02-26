//
// Created by Jesson on 2020/6/10.
//

#include <cstdlib>
#include <assert.h>
#include <cstdio>
#include "LinkedList.h"
//创建node
Node_* make(int data){
    Node_* node = static_cast<Node_ *>(malloc(sizeof(Node)));
    assert(node !=NULL);
    node->next = nullptr;
    node->data = data;
    return node;
}
//Node的资源释放
void myfree(Node_* node){
    free(node);
    node = NULL;
}
//Node节点的打印
void visit(Node_* node){
    assert(node !=NULL);
    printf("[%p | %d]\n",node,node->data);
}
//linkedlist
LinkedList_* create(){
    LinkedList_* list = static_cast<LinkedList_ *>(malloc(sizeof(LinkedList_)));
    assert(list != NULL);
    list->length = 0;
    list->head = make(0);
    list->tail = make(0);
    list->head->next = list->tail; //通过next绑定了指向关系
    return list;
}
//linkedlist的销毁
void destroy(LinkedList_* list){
    //做什么？遍历 把node free
    Node_* current = list->head->next;
    while (current != list->tail){
        Node_* next =  current->next;
        free(current);
        current = next;
    }
    free(list->head);
    free(list->tail);
    free(list);
    list = NULL;
}
//追加 在写基本的 数据结构的时候 初学者一定要从API的设计开始  我的代码仅供参考
//自己实现：想清楚API的设计
          //内存泄漏避免
void append(LinkedList_* list,int data){
    list->tail->data = data;
    Node_* node = make(0);
    list->tail->next = node; //建立关系
    list->tail = node;
    list->length += 1;
}
//删除元素
void deletelistbyindex(LinkedList_* list,int index){
    assert(index>0 && index < list->length);
    Node_* current = list->head->next;
    Node_* pre = list->head;
    unsigned int i = 0;
    while(current != list->tail){
        if(i == index){
            break;
        }
        pre  = current;
        current = current->next;
        i++;
    }
    if(pre->next!= nullptr){
        pre->next = current->next;
        myfree(current);
    }
    list->length -= 1;
}
//链表反转
void reverse(LinkedList_* list){
    Node_* pre = NULL;
    Node_* current = list->head;
    Node_* next = current->next;
    while (current !=NULL){
        current->next = pre;
        pre = current;
        current = next;
        next = (next == NULL?NULL:next->next);
    }
    Node_* node = list->head;
    list->head = list->tail;
    list->tail = node;
}

//打印函数
void print(LinkedList_* list){
    printf("==========list ===========\n");
    printf("length %d\n",list->length);
    printf("head==>[%p | %d]--->\n",list->head,list->head->data);
    Node_* current = list->head->next;
    while (current != list->tail){
        printf("head==>[%p | %d]--->\n",current,current->data);
        current = current->next;
    }
    printf("tail==>[%p | %d]--->\n",list->tail,list->tail->data);
}

//遍历打印
void list_foreach(LinkedList_ *list, list_callback callback){
    Node_ *current = list->head->next;
    while (current != list->tail) {
        callback(current);
        current = current->next;
    }
}

void list_traverse(LinkedList_ *list) {
    printf("===== The fields of list %p =====\n", list);
    list_foreach(list, visit);
}

//测试
void list_test(){
    LinkedList_* list = create();
    print(list);

    append(list,100);
    append(list,101);
    append(list,102);
    print(list);

    reverse(list);
    deletelistbyindex(list,2);
    print(list);
}

int main(){
    list_test();
}