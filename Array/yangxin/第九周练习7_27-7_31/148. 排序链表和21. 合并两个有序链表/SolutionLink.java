public class SolutionLink {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

/**
     * 148. 排序链表
     * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
     */
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        int length = 0;
        ListNode prev = head;
        while (prev != null) {
            prev = prev.next;
            length++;
        }
        int intv = 1;
        prev = new ListNode(0);
        prev.next = head;
        ListNode[] array;
        ListNode current;
        ListNode tail;
        ListNode left;
        ListNode right;
        while (intv < length) {
            current = prev.next;
            tail = prev;
            while (current != null) {
                left = current;
                right = cut(left, intv);
                current = cut(right, intv);

                array = merge(left, right);
                tail.next = array[0];
                tail = array[1];
            }
            intv <<= 1;
        }

        return prev.next;
    }

    private ListNode cut(ListNode head, int n) {
        while (head != null && n > 1) {
            head = head.next;
            n--;
        }

        if (head == null) {
            return null;
        }

        ListNode result = head.next;
        head.next = null;
        return result;
    }

    //按升序合并
    private ListNode[] merge(ListNode left, ListNode right) {
        ListNode head = new ListNode(0);
        ListNode result = head;
        while (left != null && right != null) {
            if (left.val < right.val) {
                head.next = left;
                head = left;
                left = left.next;
            } else {
                head.next = right;
                head = right;
                right = right.next;
            }
        }
        head.next = left == null ? right : left;
        while (head.next != null) {
            head = head.next;
        }
        return new ListNode[]{result.next, head};
    }
}