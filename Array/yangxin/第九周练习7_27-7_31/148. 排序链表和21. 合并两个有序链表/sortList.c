/**
 * 148. 排序链表
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 递归方式实现归并，空间效率不高
 */
struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    /**递归断开链表**/
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    //如果只有2个元素，直接断开，不在找中间点
    if (fast->next->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
    }

    struct ListNode *tmp = slow->next;
    slow->next = NULL;
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(tmp);
    /**递归断开链表**/
    //通过中间节点找出左右2断链表，开始进行合并排序
    struct ListNode *h = malloc(sizeof(struct ListNode));
    struct ListNode *res = h;
    while (left != NULL && right != NULL) {
        if (left->val < right->val) {
            h->next = left;
            left = left->next;
        } else {
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = left == NULL ? right : left;
    return res->next;
}