public class Homework_007 {

    // 合并两个有序链表，LeetCode第21题
    public void homework_007_021() {
        ListNode list1, list2, list;
        list1 = new ListNode(1);
        list1.listInsert(list1, 2);
        list1.listInsert(list1, 4);
        list2 = new ListNode(1);
        list2.listInsert(list2, 3);
        list2.listInsert(list2, 4);
        System.out.print("链表1的元素为：");
        list1.displayList(list1);
        System.out.print("\n链表2的元素为：");
        list2.displayList(list2);
        list = mergeTwoLists(list1, list2);
        System.out.print("\n归并后链表的元素为：");
        list.displayList(list);
    }

    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null)
            return null;
        else {
            if (l1 == null)
                return l2;
            else if (l2 == null)
                return l1;
        }
        ListNode list1 = l1, list2 = l2, list = null, prior = null, next;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                if (list == null) {
                    list = new ListNode(list1.val);
                    prior = list;
                } else {
                    next = new ListNode(list1.val);
                    prior.next = next;
                    prior = next;
                }
                list1 = list1.next;
            } else {
                if (list == null) {
                    list = new ListNode(list2.val);
                    prior = list;
                } else {
                    next = new ListNode(list2.val);
                    prior.next = next;
                    prior = next;
                }
                list2 = list2.next;
            }
        }
        while (list1 != null) {
            next = new ListNode(list1.val);
            prior.next = next;
            prior = next;
            list1 = list1.next;
        }
        while (list2 != null) {
            next = new ListNode(list2.val);
            prior.next = next;
            prior = next;
            list2 = list2.next;
        }
        return list;
    }
}
