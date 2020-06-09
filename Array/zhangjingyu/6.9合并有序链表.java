public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
    }

    /**
     * 合并两个有序链表
     * @param l1
     * @param l2
     * @return
     */
    public ListNode mergeTwoLinkList(ListNode l1,ListNode l2){
        if(l1==null) {
            return l2;
        }
        if(l2==null) {
            return l1;
        }
        ListNode head = new ListNode(-1);
        ListNode current = head;
        while (l1!=null&&l2!=null){
            if(l1.val<l2.val) {
                current.next = l1;
                l1 = l1.next;
            }else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        current.next = l1 == null ? l2 : l1;
        return head.next;

    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }





}