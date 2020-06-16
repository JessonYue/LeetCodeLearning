class ListNode {
    int val;
    ListNode next;

    public ListNode(int x) {
        val = x;
    }

    // 插入数据元素
    public void listInsert(ListNode list, int e) {
        ListNode prior = list, next;
        // 找到目标位置的前一个位置
        while (prior.next != null)
            prior = prior.next;
        next = new ListNode(e);
        next.next = prior.next;
        prior.next = next;
    }

    // 打印信息，格式为：1 —> 2 —> 3 —> 4
    public void displayList(ListNode list) {
        ListNode temp = list;
        while (temp.next != null) {
            System.out.print(temp.val + " —> ");
            temp = temp.next;
        }
        System.out.println(temp.val);
    }

    public ListNode reverseList(ListNode head) {
        if (head == null)
            return null;
        ListNode next = head.next, temp = null;
        head.next = null;
        while (next != null) {
            temp = next.next;
            next.next = head;
            head = next;
            next = temp;
        }
        return head;
    }
}