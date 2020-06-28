#include <stdio.h>

/**
 * 141. 环形链表
 * 给定一个链表，判断链表中是否有环。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。
 *
 * ListNode 因为没有使用typedef 定义别名，所以使用时必须加struct ，如果定义则直接使用别名
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *fast = head->next;
    struct ListNode *low = head;

    while (fast != low) {
        if (fast == NULL || fast->next ==NULL) {
            return false;
        }
        fast = fast->next->next;
        low = low->next;
    }

    return true;
}