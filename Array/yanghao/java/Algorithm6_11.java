package jdbc.mvc;

public class Algorithm6_11 {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		if(head.next == null) {
			return null;
		}
        int i = 1;
        ListNode k = null;
        ListNode j = head;
		ListNode node = head;
		while(node.next != null) {
			j = node;
			if (j.next == null) {
				break;
			}
			if(i >= n) {
				if (k == null) {
					k = head;
				}else {
					k = k.next;
				}
			}

            i++;
            node = node.next;
		}
		
		if (k == null) {
			return head.next;
		}
		
		ListNode delete = k.next;
		ListNode next = delete.next;
		k.next = next;
		delete.next = null;
		return head;
    }
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
