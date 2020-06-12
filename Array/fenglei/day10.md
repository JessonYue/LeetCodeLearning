```
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



#### C

```c++
// 按照路哥的数据类型 demo
struct ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    struct ListNode *merge;
    struct Node *node1, *node2;
    merge = create();
    node1 = l1->head->next;
    node2 = l2->head->next;
    while (node1 != l1->tail && node2 != l2->tail) {
        if (node2->value > node1->value) {
            append(node1->value, merge);
            node1 = node1->next;
        } else if (node2->value < node1->value) {
            append(node2->value, merge);
            node2 = node2->next;
        } else {
            append(node1->value, merge);
            append(node2->value, merge);
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    while (node1 != l1->tail) {
        append(node1->value, merge);
        node1 = node1->next;
    }
    while (node2 != l2->tail) {
        append(node2->value, merge);
        node2 = node2->next;
    }
    return merge;
}


// leetCode
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode newHead(0);
        ListNode *pi = &newHead;
        while(l1 && l2) {
            if(l1->val > l2->val) swap(l1, l2);
            pi->next = l1;
            l1 = l1->next;
            pi = pi->next;
        }
        pi->next = l1 ? l1 : l2;
        return newHead.next;
    }
};
```

