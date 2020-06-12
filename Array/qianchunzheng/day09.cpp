//
// Created by qianchunzheng on 2020/6/12.
//
#include <cstdio>

/**
 * 题目：
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，
 * 这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，
 * 时间复杂度应为 O(nodes)，nodes 为节点总数。
 * 示例 1:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * 示例 2:
 * 输入: 2->1->3->5->6->4->7->NULL
 * 输出: 2->3->6->7->1->5->4->NULL
 * 说明:
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 *
 */

struct Node_{
    int data;
    Node_* next;
}Node;

struct LinkedList_{
    int length;
    Node_* head;
    Node_* tail;
}linkedList;

class Solution{
public:
    Node_* oddList(Node_* head){
        Node_*curr = NULL;
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        Node_*evenHead = head->next, *oddHead = head, *evenLast = evenHead, *oddLast = oddHead;
        curr = head->next->next;
        bool oddFalg = true;
        while (curr != NULL){
            if (oddFalg){
                oddLast->next = curr;
                oddLast = curr;
            } else {
                evenLast->next = curr;
                evenLast = curr;
            }
            curr = curr->next;
            oddFalg = !oddFalg;
        }
        oddLast->next = evenHead;
        evenLast->next = NULL;
        return oddHead;
    }
};


int main(){
    return 0;
}
