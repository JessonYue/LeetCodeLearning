
public class MeSolution {
    class Solution {
        public ListNode oddEvenList(ListNode head) {//奇链表的头指针
            if (head == null) return null;
            ListNode odd = head;//奇链表的尾
            ListNode even = head.next;//偶链表的头指针
            ListNode evenHead = even;//偶链表的尾指针
            while (even != null && even.next != null) {
                odd.next = even.next;
                odd = odd.next;
                even.next = odd.next;
                even = even.next;
            }
            odd.next = evenHead;

            return head;
        }
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

