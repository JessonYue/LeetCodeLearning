import java.util.ArrayList;
import java.util.List;

class Solution_234 {
    public boolean isPalindrome(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        ListNode cur = head;
        while(cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }
        int first = 0;
        int end = vals.size() - 1;
        while(first < end) {
            if(!vals.get(first).equals(vals.get(end))) {
                return false;
            }
            first++;
            end--;
        }
        return true;
    }
}
