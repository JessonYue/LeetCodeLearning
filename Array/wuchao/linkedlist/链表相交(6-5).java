class Solution {
    //最先开始用暴力法，两个循环O（n^2）的解法，然后看题解发现有O（n）的解法
    //就是两个指针，一个指针从链表A开始遍历，另一个指针从链表B开始遍历，如果其中一个指针next节点为空则开始遍历另外一个链表
    //相当于将两个链表连起来，产生两个链表，一个是链表A在前，一个是链表B在前
    //如果两个链表有相交的节点的话，两个指针走的速度是一样的，到达相交节点的长度也一样，所以一定会在一个时刻相等
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA==null){
            return null;
        }
        if(headB==null){
            return null;
        }
        if(headA==headB){
            return headB;
        }
        ListNode aNext = headA;
        ListNode bNext = headB;
        while(aNext!=null||bNext!=null){
            if(aNext==null){
                aNext = headB;
            }
            if(bNext==null){
                bNext = headA;
            }
            if(aNext==bNext){
                return aNext;
            }
            aNext = aNext.next;
            bNext = bNext.next;
        }
        return null;
    }
}
