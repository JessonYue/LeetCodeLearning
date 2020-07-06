package jdbc.mvp;

public class Algorithm6_29 {

	public ListNode reverseList(ListNode head) {
		
		ListNode prew = null;
		ListNode curr = head;
		while (curr != null) {
			ListNode nextTemp = curr.next;
			curr.next = prew;
			prew = curr;
			curr = nextTemp;
		}
		
		return prew;
    }
	
	
}

class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}