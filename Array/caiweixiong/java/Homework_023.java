public class Homework_023 {

    // 返回倒数第 k 个节点，LeetCode面试题02.02
    void homework_023_0202() {
        ListNode listNode = new ListNode(1);
        listNode.listInsert(listNode, 2);
        listNode.listInsert(listNode, 3);
        listNode.listInsert(listNode, 4);
        listNode.listInsert(listNode, 5);
        listNode.displayList(listNode);
        System.out.println(String.format("The target is : %d", kthToLast(listNode, 3)));
    }

    private int kthToLast(ListNode head, int k) {
        if (head == null || k < 0)
            return -1;
        int target = -1, index = 1;
        ListNode slow = head, quick = head;
        while (quick.next != null && (index != k)) {
            quick = quick.next;
            index++;
        }
        if (index == k) {
            while (quick.next != null) {
                quick = quick.next;
                slow = slow.next;
            }
            target = slow.val;
        }
        return target;
    }
}
