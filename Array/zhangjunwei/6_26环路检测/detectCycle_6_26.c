#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//根据结点是 malloc 为结点在堆上开辟空间 地址是向上增涨的。
// 当出现环路时 环路的头结点的地址必定 小于或等于（自己指向自己） 尾结点的地址
struct ListNode *detectCycle1(struct ListNode *head) {
    struct ListNode *p = head;
    while (p != NULL && p->next != NULL) {
        if (p->next <= p)//
            return p->next;//
        p = p->next;
    }
    return NULL;//链表没有环路
}


//用快慢指针  快指针走两步  慢指针走一步
//
/**
如果链表中有环，那么快慢指针就一定可以相遇（且一定再环上，如图上的c点），此时快指针移动过的距离是慢指针的2倍，根据图中的参数，我们可以写出以下等式：
(m+y)*2=m+xn+y //这里的xn是当相遇时快指针已经在环上循环了x次，x>=1且为整数
=> m+y=xn => m=n-y+(x-1)*n //下面解释为什么写成这种形式
接下来将快指针置于表头(此时快指针在a处，慢指针在c处)，与慢指针以相同速度在链表上移动，当快指针移动到b处时，移动了m的距离，根据上面的等式可知，慢指针移动了n-y+(x-1)*n的距离。
我们来分析一下此时的慢指针在什么位置：
先移动(x-1)*n的距离，相当于在环上循环了(x-1)次，慢指针又回到了c点，然后再移动n-y的距离，如图所示，n-y正好是c点到b点的距离，说明此时慢指针也移动到了b点，即快慢指针在环路的开头节点相遇了。
https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/kuai-man-zhi-zhen-zheng-ming-bi-jiao-yan-jin-by-ch/
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (slow!=NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;//快慢指针相逢
    }
    if (fast==NULL || fast->next==NULL)return NULL;

    struct ListNode *cur = head;
    //cur 与 slow 开始一步步的走  相遇时 就是要找的环路的开头节点
    while (slow != cur) {
        slow = slow->next;
        cur = cur->next;
    }

    return cur;//链表没有环路
}