package L2;

import Base.ListNode;

public class Solution {
    /**
     * 链表滑动窗口，形成新链表 新链表的头节点很重要
     * @param l1
     * @param l2
     * @return
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(-1);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while (p != null || q != null) {
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;

            if (p != null) p = p.next;
            if (q != null) q = q.next;
        }
        if (carry > 0){
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(new int[]{2, 4, 3});
        ListNode node2 = new ListNode(new int[]{5, 6, 4});
        ListNode node = addTwoNumbers(node1, node2);
        System.out.println(node);
    }
}
