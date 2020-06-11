//
// Created by qianchunzheng on 2020/6/11.
//
#include <cstdlib>

/**
 * 题目：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * @return
 */

struct Node_{
    int data;
    Node_* next;
}Node;


Node_* createNode(int data);

Node_* createNode(int data){
    Node_* node = static_cast<Node_*>(malloc(sizeof(Node)));
    node->data = data;
    node->next = NULL;
}

/**
 * 思路：
 * 设置两个指针A和B之间的距离为n+1,A的next指向头节点
 * 移动两个指针，当B节点指向NULL时，证明A节点的next指向目标元素
 * 这样就确定了目标元素，可以删除了
 */
class Solution{
public:
    Node_* removeNode(Node_* head,int n){
        Node_* node1 =createNode(0);
        node1->next = head;
        Node_* A = node1;
        Node_* B = node1;
        //将B移动到N+1的位置
        for (int i = 0; i < n+1; ++i) {
            B = B->next;
        }
        //判断当B 不等于空的时候
        while (B != NULL){
            A = A->next;
            B = B->next;
        }
        //循环完成后，获取将要删除的节点，删除
        Node_* delNode = A->next;
        delete delNode;
        //获取返回的头节点
        Node_* node = node1->next;
        //删除哑节点
        delete node1;
    }
};



int main(){
    return 0;
}

