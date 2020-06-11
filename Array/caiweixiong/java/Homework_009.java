public class Homework_009 {

    // 奇偶链表，LeetCode第328题
    void homework_009_328() {
        ListNode list;
        list = new ListNode(1);
        list.listInsert(list, 2);
        list.listInsert(list, 3);
        list.listInsert(list, 4);
        System.out.print("排列前链表节点元素为：");
        list.displayList(list);
        list = oddEvenList(list);
        System.out.print("\n排列后链表节点元素为：");
        list.displayList(list);
    }

    private ListNode oddEvenList(ListNode head) {
        // 空链表，一个元素的链表，两个元素的链表都是不需要重排的
        if (head == null || head.next == null || head.next.next == null)
            return head;
        ListNode list1 = head, prior1 = list1, next1, list2 = head.next, prior2 = list2, next2;
        int len = 1;
        while (prior1.next != null && prior2.next != null) {  // 1,2,3,4,null
            if (len++ % 2 != 0) {   // 1.3，保持原链不变的前提下，对二取模不为0的就是奇数节点
                next1 = prior1.next.next;
                prior1.next = next1;
                prior1 = next1;
            } else {                // 2.4
                next2 = prior2.next.next;
                prior2.next = next2;
                prior2 = next2;
            }
        }
        prior1.next = list2;   // 将奇数链与偶数链连在一起
        prior2.next = null;
        return list1;
    }
}
