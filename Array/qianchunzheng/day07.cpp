#include <cstdlib>
#include <cstdio>

//
// Created by qianchunzheng on 2020/6/10.
//
struct Node_{
    int data;
    Node_* next;
}Node;

struct Linkedlist_{
    int length;
    Node_* head;
    Node_* tail;
}Linkedlist;

Linkedlist_* createList();

Node_* crateNode(int data){
    //申请内存
    Node_* node = static_cast<Node_*>(malloc(sizeof(Node_)));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * 思路：
 * 1.维护一个合并后链表的起始节点，作为最后返回使用
 * 2.维护一个指针，用来指向合并后链表的元素
 * 3.取l1和l2的元素进行比较，用上一步维护的指针指向该元素
 * 4.重复比较和移动指针，直到有一个链表为空，那么另一个链表的值肯定为最大，衔接到最后即可
 */
class Solution{

public:

    Node_* mergeTwoList(Node_* node1,Node_* node2){
        //创建起始链表节点
        Node_* node = crateNode(-1);
        //维护指针
        Node_ * point = node;
        //循环比较
        while (node1 != nullptr && node1 != nullptr){
            //如果node1的值大于node2的值，那么将起始节点的后继指向node2
            if(node1->data > node2->data){
                point->next = node2;
                node2 = node2->next;
            }else if(node1->data <= node2->data){
                point->next = node1;
                node1 = node1->next;
            }
            //上面确定完成之后，指针向后移位
            point = point->next;
        }

        //直到有一组链表为空，将另一个链表剩下的部分衔接上
        point->next = node1 == nullptr? node2 : node1;

        return node->next;

    }
};



int main(){

    return 0;
}