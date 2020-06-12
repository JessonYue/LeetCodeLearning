```
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



#### C++

```c++
// 根据路哥周末的链表数据结构
struct Node *oddEvenList(ListNode *list) {
    if (list->head->next == list->tail) {
        return NULL;
    }
    // 奇链表尾部
    Node *odd = list->head->next;
    // 奇链表头部
    Node *oddHead = odd;
    // 偶链表尾部
    Node *even = list->head->next->next;
    // 偶链表头部
    Node *evenHead = even;
    while (even != list->tail && odd != list->tail) {
        // 移动奇数指针
        odd->next = even->next;
        odd = odd->next;
        // 移动偶数指针
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return oddHead;
}


// 测试代码
void list_test() {
    struct ListNode *list1 = create();
    append(1, list1);
    append(2, list1);
    append(3, list1);
    append(4, list1);
    append(5, list1);
    append(6, list1);
    append(7, list1);
    append(8, list1);
    Node* node = oddEvenList(list1);
    visit_list(node);
}

// 打印结果
[0x7fdff8c05840 | 1]
[0x7fdff8c05860 | 3]
[0x7fdff8c05880 | 5]
[0x7fdff8c058a0 | 7]
[0x7fdff8c058c0 | 0]
[0x7fdff8c05850 | 2]
[0x7fdff8c05870 | 4]
[0x7fdff8c05890 | 6]
[0x7fdff8c058b0 | 8]



// leetCode 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 如果小于等于两项直接返回 没必要排序
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 奇链表头部和尾部
        ListNode *odd = head;
        // 偶链表头部和尾部
        ListNode *even = head->next;
        ListNode *evenHead = head->next;
        // 当奇数或偶数有一项为 NULL 时，证明到了 head 的尾部
        while (even != NULL && even->next != NULL) {
            // 移动奇数指针
            odd->next = even->next;
            odd = odd->next;
            // 移动偶数指针
            even->next = odd->next;
            even = even->next;
        }
        // 拼接奇数链表和偶数链表
        odd->next = evenHead;
        return head;
    }
};
```

