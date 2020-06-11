```
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：
给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```





#### C++

```c++
// 按照路哥讲的数据结构基础下添加
struct ListNode *removeNthFromEnd(ListNode *list, int n) {
    Node *slowPointer, *fastPointer = nullptr,*currentPointer;
    slowPointer = list->head;
    currentPointer = list->head;
    unsigned int i = 0;
    unsigned int k = n + 1;
    while (fastPointer != list->tail) {
        if (i > k) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        } else if (i == k) {
            fastPointer = currentPointer;
        } else {
            currentPointer = currentPointer->next;
        }
        i++;
    }
    Node *node = slowPointer->next;
    slowPointer->next = node->next;
    freeNode(node);
    list->length -= 1;
    return list;
}

// 测试代码
void list_test() {
    struct ListNode *list1 = create();
    append(1, list1);
    append(2, list1);
    append(3, list1);
    append(4, list1);
    append(5, list1);
    struct ListNode *list2 = removeNthFromEnd(list1,2);
    print(list2);
}
// 打印结果
==========list start===========
head[0x7fb8cc405830 | 0]
[0x7fb8cc405840 | 1]
[0x7fb8cc405850 | 2]
[0x7fb8cc405860 | 3]
[0x7fb8cc405880 | 5]
tail[0x7fb8cc405890 | 0]
==========list end===========

  
// leetCode 数据结构代码
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slowPointer, *fastPointer = nullptr,*currentPointer;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        slowPointer = newHead;
        currentPointer = newHead;
        int i = 0;
        while (currentPointer != NULL){
            if (i > n){
                 slowPointer = slowPointer->next;
                 fastPointer = fastPointer->next;
            } else if (i == n){
                fastPointer = currentPointer;
            }
            currentPointer = currentPointer->next;
            i++;
        }
        ListNode *temp = slowPointer->next;
        slowPointer->next = temp->next;
        return newHead->next;
    }
};
```

