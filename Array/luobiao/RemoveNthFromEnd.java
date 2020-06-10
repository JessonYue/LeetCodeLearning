/**

19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

解题思路：对于java来说这里主要是确定删除位置，首先第一种就是先遍历整个链表，确定链表的大小，在根据给定的数值，遍历删除该节点，另外一个方式就是使用两组链表，第一个先便利到n个节点，
然后在遍历第一链表，并使第二个链表指向下一个，最终等第一个链表结束后，第二个链表所指向就是需要删除的节点
**/


class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) {
            return null;
        }

        ListNode firstHead = head;
        ListNode secondHead = head;
         ListNode preHead = head;

        for(int i=0; i<n; i++){
            firstHead = firstHead.next;
        }

        while(firstHead != null && firstHead.next != null){
            preHead = secondHead;
            secondHead = secondHead.next;
            firstHead = firstHead.next;
        }

       if(secondHead == preHead) {
            if(secondHead.next == null) {
                head = null;
            } else if (firstHead == null){
                head = secondHead.next;
            } else {
                secondHead.next = secondHead.next.next;
            }

        } else {

            if(secondHead.next == null ) {
                preHead.next = null;
            } else {
                secondHead.next = secondHead.next.next;
            }
        }

        
        return head;
    }
}