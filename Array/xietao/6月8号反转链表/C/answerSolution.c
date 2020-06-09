//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {

    return 0;
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while(current != NULL){
        struct ListNode* tem = current->next;
        current->next = prev;
        prev = current;
        current = tem;
    }
    return prev;

}






