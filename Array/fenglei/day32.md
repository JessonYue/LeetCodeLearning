```c
给定一个有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

```





#### C

```c
// 方法一 连续分配的内存是递增的
struct ListNode *detectCycle(struct ListNode *head) {
    if (NULL == head) return NULL;
    struct ListNode *pointer = head;
    while (pointer && pointer->next) {
        if (pointer >= pointer->next){
            return pointer->next;
        }
        pointer = pointer->next;
    }
    return NULL;
}


// 方法二 快慢指针找相遇点
struct ListNode *detectCycle(struct ListNode *head) {
    if (NULL == head) return NULL;
    struct ListNode *fastPointer = head;
    struct ListNode *slowPointer = head;
    while (fastPointer && slowPointer && fastPointer->next) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer) {
            slowPointer = head;
            while (slowPointer != fastPointer) {
                slowPointer = slowPointer->next;
                fastPointer = fastPointer->next;
            }
            return slowPointer;
        }
    }
    return NULL;
}
```

