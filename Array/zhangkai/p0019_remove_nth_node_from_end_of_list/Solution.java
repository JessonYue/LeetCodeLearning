package com.github.leetcode.p0019_remove_nth_node_from_end_of_list;

/**
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * <p>
 * 删除链表的倒数第N个节点：
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * <p>
 * 示例：
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 说明：
 * 给定的 n 保证是有效的。
 * 进阶：
 * 你能尝试使用一趟扫描实现吗？
 * <p>
 * 时间复杂度在 O()
 */
class Solution {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    /**
     * --------------------我的代码--------------------
     */
    //思考：一趟扫描实现,快慢指针
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //只有一个元素的时候
        if (head.next == null) {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        int count = 0;
        while (fast.next != null) {
            if (count >= n) {
                slow = slow.next;
            }
            fast = fast.next;
            count++;
        }
        //System.out.println(fast.val);
        //System.out.println(slow.val);

        //删除是头结点
        if (count == n - 1) {
            return head.next;
        }
        //此时的slow应为待删除元素的前一个节点
        slow.next = slow.next.next;
        return head;
    }


    //这种方法需要两层扫描实现
  /*  public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int length = 0;
        while (temp != null) {
            temp = temp.next;
            length++;
        }
        //链表只有一个元素的情况下
        if (length == 1) {
            return null;
        }
        //链表长度大于1，则需要找到待删除节点的前一个节点
        int index = length - n;//index为要删除的位置的下标；如当n=2，index=3，删除值为4
        //如果删除的是头节点
        if (index == 0) {
            head = head.next;
            return head;
        }

        //非头结点
        temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp.next;
        }
        //此时temp为待删除节点的前一个节点
        //System.out.println(temp.val);
        temp.next = temp.next.next;
        return head;
    }*/
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        /*    listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);*/
        print(listNode);
        ListNode removeList = solution.removeNthFromEnd(listNode, 2);
        System.out.println("处理之后的List:");
        print(removeList);
    }

    public static void print(ListNode listNode) {
        while (listNode != null) {
            System.out.print(listNode.val + "-->");
            listNode = listNode.next;
        }
        System.out.println();
    }

    /**
     * --------------------别人的代码--------------------
     */

}