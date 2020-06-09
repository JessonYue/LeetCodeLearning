package example.lei.lib.ListNode;

import com.sun.org.apache.bcel.internal.generic.IF_ACMPEQ;

public class day1 {

    public static void main(String args[]) {

    }

    //这个还是很好懂得，但是是两个列表都在循环
    public ListNode getNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode curA = headA;
        ListNode curB = headB;

        for (; curA != null; curA = curA.next) {
            for (; curB != null; curB = curB.next) {
                if (curA == curB) {
                    return curA;
                }
            }
        }
        return null;
    }

    //那个高级算法，我需要在琢磨琢磨实现，道理是懂了

}
