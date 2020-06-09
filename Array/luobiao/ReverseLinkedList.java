/**
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

主要思路：通过链表的属性对调前一个和后一个的赋值关系，最后判断链表的下一个不为空结束，此处的pre即是所要的最终链表

*/

class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) {
            return head;
        }

        ListNode pre = null;
        ListNode current = head;
        ListNode next = current.next;
        while(current != null) {
            current.next = pre;
            pre = current;
            current = next;
            next = (next == null ? null : next.next);
        }
        
        return pre;
    }
}