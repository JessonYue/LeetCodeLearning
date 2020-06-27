public class Homework_018 {

    // 环型链表，LeetCode第141题
    void homework_018_141() {
        ListNode node = new ListNode(3);
        ListNode temp = node;
        node.next = null;
        node.listInsert(node, 2);
        node.listInsert(node, 0);
        node.listInsert(node, -4);
        while (temp.next != null)   // 找到尾指针
            temp = temp.next;
        temp.next = node.next;      // 成环
        if (hasCycle(node))
            System.out.println("linker is cycle");
        else
            System.out.println("linker is not cycle");
    }

    private boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;
        ListNode slow = head, quick = head;
        while (quick != null && quick.next != null) {
            quick = quick.next.next;
            slow = slow.next;
            if (quick == slow) {
                return true;
            }
        }
        return false;
    }
}
