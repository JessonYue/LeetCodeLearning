public class Homework_020 {

    // 删除链表中的节点，LeetCode第237题
    void homework_020_237() {
        ListNode head, start;
        head = new ListNode(3);
        head.next = null;
        head.listInsert(head, 2);
        head.listInsert(head, 0);
        head.listInsert(head, -4);
        head.displayList(head);
        deleteNode(head);
        head.displayList(head);
    }

    private void deleteNode(ListNode node) {
        if (node == null || node.next == null)
            return;
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
