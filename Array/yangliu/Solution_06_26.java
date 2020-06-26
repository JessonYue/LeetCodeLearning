import java.security.PrivateKey;

public class Solution_06_24 {

    public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}

  class ListNode {
      int val;
      ListNode next;
     ListNode(int x) {
         val = x;
          next = null;
      }
  }

}
