#include <stdlib.h>

//
// Created by 吴超 on 2020/7/27.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *temp = dummy;
    int length = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        length++;
    }
    for(int i=1;i<length;i=i<<1){
        temp = dummy;
        for(int j=0;j<length-i;j=j+(i<<1)){
            struct ListNode* leftHead = temp->next;
            struct ListNode* rightHead = leftHead;
            int leftEnd=0,rightEnd=0;
            while(rightEnd<i){
                rightHead = rightHead->next;
                rightEnd++;
            }
            rightEnd=0;
            while(leftEnd<i&&rightEnd<i&&rightHead!=NULL){
                if(leftHead->val<rightHead->val){
                    temp->next = leftHead;
                    leftHead = leftHead->next;
                    leftEnd++;
                } else {
                    temp->next = rightHead;
                    rightHead = rightHead->next;
                    rightEnd++;
                }
                temp = temp->next;
            }
            while(leftEnd<i){
                temp->next = leftHead;
                leftHead = leftHead->next;
                leftEnd++;
                temp = temp->next;
            }
            while (rightEnd<i&&rightHead!=NULL){
                temp->next = rightHead;
                rightHead = rightHead->next;
                rightEnd++;
                temp = temp->next;
            }
            temp->next = rightHead;
        }
    }
    return dummy->next;
}
