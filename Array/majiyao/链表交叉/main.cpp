#include <iostream>

//定义链表结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//c++的链表还是不太明白，该题目的思路明白了，今天在加班，估计要通宵了，后面要把这块补充上
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2){
        if (p1 == NULL){
            p1 = headB;
        } else{
            p1 = p1->next;
        }
        if (p2 == NULL ){
            p2 = headA;
        } else{
            p2 = p2->next;
        }
    }
    return p1;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}

