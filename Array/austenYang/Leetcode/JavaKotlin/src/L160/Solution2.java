package L160;

import Base.ListNode;

import java.util.HashSet;

public class Solution2 {


    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode node1 = headA;
        ListNode node2 = headB;
        while (node1 != null) {
            l1++;
            node1 = node1.next;
        }
        while (node2 != null) {
            l2++;
            node2 = node2.next;
        }
        int distance = 0;
        if (l1 > l2) {
            node1 = headA;
            node2 = headB;
            distance = l1 - l2;
        } else {
            node1 = headB;
            node2 = headA;
            distance = l2 - l1;
        }

        while (distance > 0) {
            node1 = node1.next;
            distance--;
        }

        while (node1 != null && node2 != null) {
            if (node1 == node2) {
                return node1;
            }

            node2 = node2.next;
            node1 = node1.next;
        }
        return null;
    }

    public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        HashSet<ListNode> container = new HashSet<>();
        while (headA != null) {
            container.add(headA);
            headA = headA.next;
        }

        while (headB != null) {
            if (container.contains(headB)) {
                return headB;
            }
            headB = headB.next;
        }
        return null;
    }

    public ListNode getIntersectionNode3(ListNode headA, ListNode headB) {
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != null || pB != null) {
            if (pA == pB) {
                return pA;
            }
            pA = pA == null ? pB : pA.next;
            pB = pB == null ? pA : pB.next;
        }
        return null;
    }
}
