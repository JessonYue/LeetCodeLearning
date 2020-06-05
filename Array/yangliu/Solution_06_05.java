public class Solution_06_05 {
    public static void main(String[] args) {


    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode currentA = headA;
        ListNode currentB = headB;
        for (; currentA != null; currentA = currentA.next) {
            currentB=headB;
            for (; currentB != null; currentB = currentB.next) {
                if (currentA == currentB) return currentA;
            }
        }
        return null;
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
