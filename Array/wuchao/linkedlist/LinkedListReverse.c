#include <stdio.h>
//
// Created by 吴超 on 2020/6/8.
//
struct ListNode {
    int val;
    struct ListNode *next;
};
//由于之前已经用java实现一遍了，这次用C语言实现一遍。
//本质就是一个双指针，current指针指向当前节点，prev指针指向上一个节点。
//逐个遍历，将current的next指针指向prev，然后prev向前移动一步，current向前移动一步，直到遍历到链表尾部。
//这里有一个点需要注意，就是在将current的next指针指向prev之前，需要先将它指向的下一个节点缓存一下（用next指针缓存），在current指针向前移动这一步的时候，赋值给current指针。
//因为如果不缓存，当current的next指向prev之后，就无法再访问到这个节点了。
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while (current!=NULL){
        struct ListNode* next = current->next;
        current->next = prev;
        prev =current;
        current = next;
    }
    return prev;
}
