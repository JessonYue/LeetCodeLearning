```
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

进阶：
你能用 O(1)（即，常量）内存解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```







### C

```c

#include <stdio.h>
#include <mm_malloc.h>
#include <string.h>
#include<ctype.h>
#include <stdbool.h>

typedef int data;

typedef struct ListNode {
    data val;
    struct ListNode *next;
} ListNode;


ListNode *init(int data) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = data;
    return node;
}

ListNode *append(int data, ListNode *cur) {
    ListNode *node = malloc(sizeof(ListNode));
    node->val = data;
    node->next = NULL;
    cur->next = node;
    cur = cur->next;
    return cur;
}

void printNode(ListNode *head) {
    ListNode *node = head;
    while (node) {
        printf("node[%p,%d]\n", node, node->val);
        node = node->next;
    }
}

//int hasCycle(struct ListNode *head) {
//    if (head == NULL || head->next == NULL) {
//        return 0;
//    }
//    struct ListNode *fastPointer, *slowPointer;
//    fastPointer = head->next;
//    slowPointer = head;
//    while (slowPointer != NULL) {
//        while (fastPointer != NULL) {
//            printf("slowPointer[%p,%d] - fastPointer[%p,%d]\n", slowPointer, slowPointer->val, fastPointer,
//                   fastPointer->val);
//            if (slowPointer == fastPointer) {
//                return 1;
//            }
//            fastPointer = fastPointer->next;
//        }
//        slowPointer = slowPointer->next;
//        fastPointer = slowPointer == NULL ? NULL : slowPointer->next;
//    }
//    return 0;
//}



bool hasCycle(struct ListNode *head) {
    if (NULL == head)
        return false;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
//        printf("slowPointer[%p,%d] - fastPointer[%p,%d]\n", slow, slow->val, fast,
//               fast->val);
        fast = fast->next;
        printf("slowPointer[%p,%d] - fastPointer[%p,%d]\n", slow, slow->val, fast,
               fast->val);
        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    ListNode *node = init(1);
    ListNode *head = node;
    node = append(2, node);
    node = append(3, node);
    node = append(4, node);
    node = append(5, node);
    node = append(6, node);
    node = append(7, node);
    node = append(8, node);
    node = append(9, node);
    node = append(10, node);
    node = append(11, node);
    node = append(12, node);
    node = append(13, node);
    
    node->next = head;
    int flag = hasCycle(head);
    printf("result = %d\n", flag);
    return 0;
}

```

