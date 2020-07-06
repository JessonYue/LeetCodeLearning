package day31;

public class day31_leetcode_interview0202 {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    //k=2
    //null-->1-->2-->3-->4-->5
    //           p



                       //2
    //null<--1<--2<--3<--4<--5
                            //2
    //null<--1<--2<--3<--4<--5<--6
    //                  pre  cur

    public int kthToLast(ListNode head, int k) {
        ListNode fast = head;
        ListNode slow = head;

        while (k!=0){
            k--;
            fast = fast.next;
        }

        while (fast!=null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow.val;

    }
}
