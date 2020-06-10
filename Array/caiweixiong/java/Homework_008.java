public class Homework_008 {

    // 删除链表的倒数第N个节点，LeetCode第19题
    public void homework_008_019() {
        ListNode list;
        list = new ListNode(1);
        list.listInsert(list, 2);
        list.listInsert(list, 3);
        list.listInsert(list, 4);
        System.out.print("删除链表节点前的元素为：");
        list.displayList(list);
        list = removeNthFromEnd_(list, 2);
        System.out.print("\n删除链表节点前的元素为：");
        list.displayList(list);
    }

    private ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0)
            return head;
        int len = 1, no;
        ListNode temp = head;
        // 查询链表的长度
        while (temp.next != null) {
            temp = temp.next;
            len++;
        }
        if (len < n)
            return head;
        // 获取顺数需要删除的节点索引，从 0 开始
        no = len - n;
        temp = head;
        if (no == 0) {
            head = head.next;
        } else {
            // 寻找需要删除节点的前驱节点
            while (--no != 0)
                temp = temp.next;
            temp.next = temp.next.next;
        }
        return head;
    }

    // 方法二：双指针法，当找到了第 n + 1 个节点，再用一个指针从头开始，这样就可以保证两个指针间的元素为 n 个，所以第一轮循环到尾节点时，第二个指针正好在倒数第 n 个节点的前驱节点处
    ListNode removeNthFromEnd_(ListNode head, int n) {
        if (head == null || n <= 0) {
            return null;
        }
        int len = 1;
        ListNode first = head, second = head;
        while (first.next != null) {   // 寻找需要删除的节点的前驱节点
            first = first.next;
            if (len++ > n)
                second = second.next;
        }
        if (len < n)    // 如果链表的长度比目标数还小，也就是不存在节点，则直接返回原链表
            return head;
        if (len == n) { // 当需要删除的是头节点，则修改头节点后直接删除
            head = head.next;
        } else {        // 删除目标节点
            second.next = second.next.next;
        }
        return head;
    }
}
