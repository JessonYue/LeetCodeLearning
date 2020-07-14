package LInterview02_07;

import Base.ListNode;

import java.util.HashSet;

public class Solution {

    public static ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
        ListNode t1 = headA;
        ListNode t2 = headB;

        while (t1 != t2) {
            if (t1 == null) {
                t1 = headB;
            } else {
                t1 = t1.next;
            }

            if (t2 == null) {
                t2 = headA;
            } else {
                t2 = t2.next;
            }

        }

        return t1;
    }

    public static ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        ListNode pa = headA;
        HashSet<ListNode> listNodes = new HashSet<>();
        while (pa != null) {
            listNodes.add(pa);
            pa = pa.next;
        }
        ListNode pb = headB;
        while (pb != null) {
            if (listNodes.contains(pb)) {
                return pb;
            }
            pb = pb.next;
        }
        return null;
    }

    public static ListNode getIntersectionNode3(ListNode headA, ListNode headB) {
        int Alength = 0;
        int Blength = 0;

        ListNode pa = headA;
        while (pa != null) {
            Alength++;
            pa = pa.next;
        }
        ListNode pb = headB;
        while (pb != null) {
            Blength++;
            pb = pb.next;
        }
        int distance;
        if (Alength >= Blength) {
            distance = Alength - Blength;
            while (distance > 0) {
                headA = headA.next;
                distance--;
            }
        } else {
            distance = Blength - Alength;
            while (distance > 0) {
                headB = headB.next;
                distance--;
            }
        }

        while (headA != null && headB != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }

    public static ListNode getIntersectionNode4(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }

        int ALength = 0;
        int BLength = 0;

        ListNode p = headA;
        ListNode q = headB;

        while (p != null) {
            ALength++;
            p = p.next;
        }
        while (q != null) {
            BLength++;
            q = q.next;
        }
        int distance ;
        if (ALength > BLength) {
            p = headA;
            q = headB;
            distance = ALength - BLength;
        } else {
            p = headB;
            q = headA;
            distance = BLength - ALength;
        }

        for (int i = 0; i < distance; i++) {
            p = p.next;
        }
        while (p != null && q != null) {
            if (p == q) {
                return p;
            }
            p = p.next;
            q = q.next;
        }
        return null;
    }

    // listA = [4,1,8,4,5],
    // listB = [5,0,1,8,4,5]
    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(4);
        ListNode listNode2 = new ListNode(1);
        ListNode listNode3 = new ListNode(8);
        ListNode listNode4 = new ListNode(4);
        ListNode listNode5 = new ListNode(5);
        ListNode listNode6 = new ListNode(5);
        ListNode listNode7 = new ListNode(0);
        ListNode listNode8 = new ListNode(1);

        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode5;

        listNode6.next = listNode7;
        listNode7.next = listNode8;
        listNode8.next = listNode3;

        ListNode intersectionNode1 = getIntersectionNode1(listNode1, listNode6);
        ListNode intersectionNode2 = getIntersectionNode2(listNode1, listNode6);
        ListNode intersectionNode3 = getIntersectionNode3(listNode1, listNode6);
        ListNode intersectionNode4 = getIntersectionNode4(listNode1, listNode6);
        System.out.println(intersectionNode1.val);
        System.out.println(intersectionNode2.val);
        System.out.println(intersectionNode3.val);
        System.out.println(intersectionNode4.val);
    }
}
