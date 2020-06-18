public class Homework_010 {

    // 回文链表，LeetCode第234题
    void homework_010_234() {
        ListNode list;
        list = new ListNode(1);
        list.listInsert(list, 2);
        list.listInsert(list, 2);
        list.listInsert(list, 1);
        System.out.print("链表节点元素为：");
        list.displayList(list);
        if (isPalindrome(list))
            System.out.println("is palindrome");
        else
            System.out.println("not palindrome");
        System.out.print("链表节点元素为：");
        list.displayList(list);
    }

    private boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;
        boolean isPalindrome = true;
        ListNode middleList = getListMiddle(head);
        ListNode reverseEndList = middleList.reverseList(middleList);
        ListNode currentList = head, reverseList = reverseEndList;

        while (reverseList != null && isPalindrome) {
            if (currentList.val != reverseList.val)
                isPalindrome = false;
            currentList = currentList.next;
            reverseList = reverseList.next;
        }

        middleList.next = reverseEndList.reverseList(reverseEndList).next;
        return isPalindrome;
    }

    private ListNode getListMiddle(ListNode head) {
        ListNode slow = head, quick = head;
        while (quick != null && quick.next != null) {
            quick = quick.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
