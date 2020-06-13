
public class MeSolution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newNode = new ListNode(0);
        newNode.next = head;
        ListNode p1  = newNode;
        ListNode p2  = newNode;
        while(n >= 0){
            p1 = p1.next;
            n = n-1;
        }

        while(p1 != null){
            p1 = p1.next;
            p2 = p2.next;
        }
        p2.next = p2.next.next;

        return newNode.next;

    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

}

