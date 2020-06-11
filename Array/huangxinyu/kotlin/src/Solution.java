import com.ryujin.algorithm.ListNode;


public class Solution {
    /**
     * 删除倒数第n个节点
     */
    public ListNode removeNthFromEnd(ListNode listNode, int n) {
        ListNode preHead = new ListNode(-1, listNode);
        ListNode p1 = listNode;
        int i = 0;
        while (i < n) {
            assert p1 != null;
            p1 = p1.getNext();
            i++;
        }
        ListNode p2 = preHead;
        while (p1 != null) {
            p1 = p1.getNext();
            p2 = p2.getNext();
        }
        p2.setNext(p2.getNext().getNext());
        return preHead.getNext();
    }
}