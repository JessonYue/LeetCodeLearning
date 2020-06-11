/**
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路：这道题的主要问题是如何把原先链表拆分成两个两个奇偶链表，如果拆分成功后，直接通过奇链表next指向偶链表，针对拆分链表，我们在这里直接创建偶数链表，把原来的链表用来存储奇数链表
，并在创建两个当前节点，，根据计数器，来区分奇数偶数位置，如果为基数则通过next指向它，偶数也一样，这一块一定要记住在最后一定要在遍历完成后将偶数链表的next设置为空，不然会看到偶数链表
最后会多一条奇数值，最后将奇数链表next指向偶数链表的next，至于为什么是偶数链表的next，是由于我们在创建偶数链表时有个头，这个头的值为零
**/

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null) {
            return head;
        }

        ListNode currentListNode = head;
        ListNode oddListNode = null;
        ListNode evenListNode = new ListNode();
        ListNode evenCurrentListNode = evenListNode;

        int i = 1;
        while(currentListNode != null) {
            if(i%2 == 1) {
                if(oddListNode == null) {
                    oddListNode = currentListNode;
                } else {
                    oddListNode.next = currentListNode;
                    oddListNode = oddListNode.next;
                }

            } else {
                evenCurrentListNode.next = currentListNode;
                evenCurrentListNode = evenCurrentListNode.next;
            }
            currentListNode = currentListNode.next;
            i++;
        }
        evenCurrentListNode.next = null;

        oddListNode.next = evenListNode.next;
        return head;
    }

}