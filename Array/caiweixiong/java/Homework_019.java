public class Homework_019 {

    // 环路检测，LeetCode面试题02.08
    void homework_019_0208() {
        // 初始化链表
        ListNode head, start;
        head = new ListNode(3);
        head.next = null;
        head.listInsert(head, 2);
        head.listInsert(head, 0);
        head.listInsert(head, -4);
        head.next.next.next.next = head.next;
        start = detectCycle(head);
        if (start == null)
            System.out.println("linker is not cycle");
        else
            System.out.println(String.format("linker cycle ele is : %d", start.val));
        head.next.next.next.next = null;  // 断开链环
    }

    private ListNode detectCycle(ListNode head) {
        ListNode elem = getCycleElem(head);
        if (elem == null)
            return null;
        ListNode first = head, start = elem, next = elem, temp = elem;
        int min = Integer.MAX_VALUE, count = 1;
        while (start != next.next) {
            while (first != next) {
                first = first.next;
                if (++count > min)
                    break;
            }
            if (min > count) {
                temp = first;
                min = count;
            }
            count = 1;
            first = head;
            next = next.next;
        }
        return temp;
    }

    private ListNode getCycleElem(ListNode head) {
        if (head == null || head.next == null)
            return null;
        ListNode elem = null, slow = head, quick = head;
        while (quick.next != null && quick.next.next != null) {
            slow = slow.next;
            quick = quick.next.next;
            if (slow == quick) {
                elem = slow;
                break;
            }
        }
        return elem;
    }
}
