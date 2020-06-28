package DataStructure;

public class ListNode {
    public int val;
    public ListNode next;

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int[] arrays) {
        if (arrays == null || arrays.length == 0) {
            throw new IllegalArgumentException("create single linked list, arrays must valid !");
        }
        this.val = arrays[0];
        ListNode cur = this;
        for (int i = 1; i < arrays.length; i++) {
            cur.next = new ListNode(arrays[i]);
            cur = cur.next;
        }
    }

    public ListNode getNodeFromIndex(int index) {
        ListNode cur = this;
        for (int i = 0; i < index; i++) {
            cur = cur.next;
        }
        return cur;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        ListNode cur = this;
        sb.append("Head :");
        while (cur != null) {
            sb.append(cur.val);
            sb.append("--->");
            cur = cur.next;
        }
        sb.append("NULL");
        return sb.toString();
    }
}
