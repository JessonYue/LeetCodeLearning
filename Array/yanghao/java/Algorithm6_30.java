package jdbc.mvp;

public class Algorithm6_30{
	
	public int kthToLast(ListNode head, int k) {
		ListNode pListNode = head;
		for(int i = 0; i < k ; i++) {
			pListNode = pListNode.next;
		}
		
		while (pListNode != null) {
			pListNode = pListNode.next;
			head = head.next;
		}
		return head.val;
    }
}


class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}