

//参考了力扣的解法，最终仿照自己写了一边，对思路很有启发

public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode pa = headA;
        ListNode pb = headB;
        while (pa != pb) {
            if (pa != null) {
                pa = pa.next;
            }else{
                pa = headB;
            }
            if (pb != null) {
                pb = pb.next;
            }else{
                pb = headA;
            }
        }
        if (pa ==null) {
            return null;
        }
        return pa;
    }