```
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

### C

```c
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode *leftPointer,*midPointer,*rightPointer;
    leftPointer = NULL;
    midPointer = head;
    rightPointer = midPointer->next;
    while (midPointer != NULL){
        midPointer->next =leftPointer;
        leftPointer = midPointer;
        midPointer = rightPointer;
        rightPointer = (rightPointer == NULL ? NULL : rightPointer->next);
    }

    return leftPointer;
}
```

