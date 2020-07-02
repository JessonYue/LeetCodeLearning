public class Homework_006 {

    // 反转链表，LeetCode第206题
    public void homework_006_206() {
        ListNode list;
        list = new ListNode(0);
        list.listInsert(list, 9);
        list.listInsert(list, 1);
        list.listInsert(list, 2);
        list.listInsert(list, 4);
        System.out.print("链表反转前的元素为：");
        list.displayList(list);
        System.out.print("\n");
        list = list.reverseList_(list);
        System.out.print("链表反转后的元素为：");
        list.displayList(list);
        System.out.print("\n");
    }
}
