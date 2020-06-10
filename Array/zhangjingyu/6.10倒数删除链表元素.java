public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);
        printList(deleteLastNumber(listNode,2));
        printList(deleteLastNumber2(listNode,2));
    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    /**
     * 打印链表
     * @param listNode
     */
    private void printList(ListNode listNode) {
        while(listNode!=null) {
            System.out.print(listNode.val+"     ");
            listNode = listNode.next;
        }
    }

    /**
     * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
     */
    public ListNode deleteLastNumber(ListNode head,int n){
        ListNode first = head;
        ListNode dummy = new ListNode(0);
        dummy.next = first;
        int length = 0;
        while(first!=null) {
            length++;
            first = first.next;
        }
        length = length-n;
        first = dummy;
        while(length>0) {
            length--;
            first = first.next;
        }
        first.next = first.next.next;
        return dummy.next;
    }

    /**
     * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
     */
    public ListNode deleteLastNumber2(ListNode head,int n){
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        for(int i = 0; i < n+1; i++) {
            first = first.next;
        }
        while(first!=null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return dummy.next;
    }





}