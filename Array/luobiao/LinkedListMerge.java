/**

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路：首先根据遍历链表1，判断链表1的值与链表2的值，如果链表2大，则链表1切换到下一个，否则，将链表1的下一个结点指向链表2，作为新的链表1，并将之前链表1剩余的切换到链表2上，再次进行比较
**/

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode switchNode = l2;
        ListNode l1Current = l1;
        ListNode preCurrent = l1;
        ListNode tempCurrent = null;

        if(l1Current == null) {
            return l2;
        }

        if(l2 == null) {
            return l1;
        }

        while(l1Current != null) {
            
            if(l1Current.val <= switchNode.val) {
                preCurrent = l1Current;
                l1Current = l1Current.next;
                continue;
            } else {
                tempCurrent = switchNode;
                switchNode = l1Current;
                if(l1Current == preCurrent) { //l2链表在前，即l2的值小
                    preCurrent = tempCurrent;
                    l1 = preCurrent;
                    l1Current = preCurrent;
                } else {
                    preCurrent.next = tempCurrent;
                    l1Current = preCurrent;
                }
                
            }
            
        }

        if(switchNode != null) {
            preCurrent.next = switchNode;
        }

        return l1;
    }
}