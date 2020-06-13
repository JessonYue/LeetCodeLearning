/**

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

结题思路：第一想法就是创建一个新的链表，该链表是head链表的反转链表，然后在遍历两个链表，判断值是否相等即可，这里有个问题，本来想着优化，做了个计数器，就是在反转的时候同时计算链表
的总长度，然后再比较两个链表是否相等的时候，进行判断，如果当前的计数超过链表的总长度时，就结束判断，但是加了之后，在力扣（LeetCode）上发现效率更低了
**/

class Solution {
    // private int count = 0;
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) {
            return true;
        }

        ListNode reverseListNode = reverseList(head);
        ListNode currentListNode = head;
        ListNode currentreverseListNode = reverseListNode;

        // int i = 0; 
        // int num = count/2;
        while(currentListNode != null && currentreverseListNode != null /**&& i < num **/) {
            if(currentListNode.val != currentreverseListNode.val) {
                return false;
            }
            currentListNode = currentListNode.next;
            currentreverseListNode = currentreverseListNode.next;
            // i++;
        }

        return true;
    }

    public ListNode reverseList(ListNode head) {
        ListNode result = null;
        while (head != null) {
            ListNode temp = new ListNode(head.val);
            temp.next = result;
            result = temp;
            head = head.next;
            // count++;
        }
        return result;
    }
}