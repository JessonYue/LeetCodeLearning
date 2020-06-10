/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 *给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 *参考了示例，不然也只想到了用暴力法遍历一次得到长度，并添加进数组，得到长度为m的数组，
 *            然后根据n删除数组的第m-n个元素
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    struct ListNode* q = head;
    struct ListNode* preQ = NULL;
    while(p){
        n--;
        p = p->next;
        if(n<0){
            preQ = q;
            q = q->next;
        }
    }
    if(q == head){
        head = head->next;
    }else{
        preQ->next = q->next;
    }
    q->next = NULL;
    free(q);
    return head;

}
