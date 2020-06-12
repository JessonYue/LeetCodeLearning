//
// Created by 12 on 2020/6/8.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 链表相交
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    if (headA == headB) {
        return headA;
    }

    int aLength = 0;
    int bLength = 0;
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while (a != NULL) {
        aLength++;
        a = a->next;
    }

    while (b != NULL) {
        bLength++;
        b = b->next;
    }

    if (a != b) {
        return NULL;
    }
    a = headA;
    b = headB;
    int k = aLength - bLength;
    while (k != 0) {
        if (k > 0) {
            k--;
            a = a->next;
        } else {
            k++;
            b = b->next;
        }
    }

    while (a != b) {
        a = a->next;
        b = b->next;
    }

    return a;
}

/**
 * 面试题24. 反转链表
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 */
struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *pre = NULL;
    struct ListNode *current = head;
    struct ListNode *next = current->next;

    while (next != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = current->next;
    }

    current->next = pre;

    return current;
}

/**
 * 21. 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }

    if (l2 == NULL) {
        return l1;
    }

    struct ListNode *head = malloc(sizeof(struct ListNode));
    //c语言里要赋值null，不然好像就指向不知道的地方去了。c语言里一切值都要初始化
    head->next = NULL;
    struct ListNode *a = NULL;
    struct ListNode *b = NULL;
    if (l1->val < l2->val) {
        head->val = l1->val;
        a = l1->next;
        b = l2;
    } else {
        head->val = l2->val;
        a = l1;
        b = l2->next;
    }

    struct ListNode *current = head;
    while (a != NULL && b != NULL) {
        if (a->val < b->val) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    while (a != NULL) {
        current->next = a;
        a = a->next;
        current = current->next;
    }

    while (b != NULL) {
        current->next = b;
        b = b->next;
        current = current->next;
    }

    return head;
}




/**
 * 19. 删除链表的倒数第N个节点
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 */
//力扣给成出的最佳答案，写法更简洁，更优秀
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
//    struct ListNode *p = head, *q = head;
//    while(p){
//        if(n < 0){
//             q = q -> next;
//        }
//        n--;
//        p = p -> next;
//    }
//    if(n == 0){ return head -> next; }
//    q -> next = q -> next -> next;
//    return head;
//}
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head == NULL) {
        return NULL;
    }

    if (n <= 0) {
        return NULL;
    }

    struct ListNode *tmp1 = head;
    struct ListNode *tmp2 = head;
    int i = 0;
    //再让指针移动n个位置，然后两个再同时递增，
    while (tmp1 != NULL && i < n) {
        tmp1 = tmp1->next;
        i++;
    }
    //如果i跟n相等并且tmp1为null说明，倒数为链表的头，需要删除头节点
    if (tmp1 == NULL && i == n) {
        struct ListNode *newHead = head->next;
        free(head);
        return newHead;
    }

    if (tmp1 == NULL) {
        return NULL;
    }
//    //先走一步
    tmp1 = tmp1->next;
//先走的到尾节点，后一个是n的前一个节点
    while (tmp1 != NULL) {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    struct ListNode *delete = tmp2->next;
    tmp2->next = tmp2->next->next;
    //释放删除的节点资源
    free(delete);

    return head;
}

/**
 * 328. 奇偶链表
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
 * 请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 *
 * 参考学习官方解题思路
 */
struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    //奇数尾节点
    struct ListNode *odd = head;
    //偶数尾节点
    struct ListNode *even = head->next;
    //偶数头节点
    struct ListNode *evenHead = even;

    while (even != NULL && evenHead != NULL) {
        //奇数尾指向偶数尾的下一个
        odd->next = even->next;
        //如果奇数尾已经为null，说明到头了，就停止遍历
        if (odd->next == NULL) {
            break;
        }
        //更新奇数尾节点位置
        odd = odd->next;
        //偶数尾指向奇数的下一个，就是需要的偶数节点
        even->next = odd->next;
        //更新偶数尾节点位置
        even = even->next;
    }
    //把偶数连接到奇数尾部
    odd->next = evenHead;

    return head;
}

//翻转链表
struct ListNode *reverseList2(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *tmp = cur;
    while (cur != NULL) {
        cur = cur->next;
        tmp->next = pre;
        pre = tmp;
        tmp = cur;
    }

    return pre;
}

/**
 * 234. 回文链表
 * 请判断一个链表是否为回文链表。
 * 参考学习官方思路
 */
bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    //通过快慢指针找到中间点
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //记录中间点指针
    struct ListNode *mid = slow;
    //如果为奇数跳过中间点
    if (fast != NULL) slow = slow->next;
    //翻转后半部链表
    struct ListNode *newHead = reverseList2(slow);
    struct ListNode *cur = head;
    struct ListNode *curNew = newHead;
    //前半部和翻转后的后半部比较，最后恢复链表
    while (curNew != NULL) {
        if (curNew->val != cur->val) {
            mid->next = reverseList2(newHead);
            return false;
        }
        curNew = curNew->next;
        cur = cur->next;
    }

    mid->next = reverseList2(newHead);
    return true;
}


void main() {
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l1->next = l2;
    l2->val = 2;
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l2->next = l3;
    l3->val = 3;
    struct ListNode *l4 = malloc(sizeof(struct ListNode));
    l3->next = l4;
    l4->val = 2;
    struct ListNode *l5 = malloc(sizeof(struct ListNode));
    l4->next = l5;
    l5->val = 1;
    l5->next = NULL;

    struct ListNode *l11 = malloc(sizeof(struct ListNode));
    l11->val = 1;
    struct ListNode *l12 = malloc(sizeof(struct ListNode));
    l11->next = l12;
    l12->val = 0;
    struct ListNode *l13 = malloc(sizeof(struct ListNode));
    l12->next = l13;
    l13->val = 1;
    l13->next = NULL;
//    struct ListNode *l14 = malloc(sizeof(struct ListNode));
//    l13->next = l14;
//    l14->val = 1;
//    l14->next = NULL;

//    struct ListNode *head = reverseList2(l1);
//    while (head != NULL) {
//        printf("%d->", head->val);
//        head = head->next;
//    }

    printf("%d", isPalindrome(l1));
}