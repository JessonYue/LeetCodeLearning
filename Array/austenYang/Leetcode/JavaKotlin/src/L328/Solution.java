package L328;

import DataStructure.ListNode;



/**
 * https://leetcode.com/problems/odd-even-linked-list/
 */
public class Solution {
    /**
     * 思路1：
     * 1.
     * 指定奇节点头
     * 指定偶节点头
     * 2.
     * 遍历 根据索引 将奇跟在后面 将偶跟在后面
     * 3.
     * 遍历完成 奇与偶相连
     *
     * @param head
     * @return
     */
    public static ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode oddHeadPre = new ListNode(-1);

        ListNode odd = head;
        oddHeadPre.next = odd;

        ListNode even = head.next;
        ListNode evenHead = even;


        ListNode cur = even.next;

        int index = 3;
        while (cur != null) {
            if (index % 2 == 1) {
                odd.next = cur;
                odd = cur;
            } else {
                even.next = cur;
                even = cur;
            }
            cur = cur.next;
            index++;
        }
        even.next = null;
        odd.next = evenHead;

        return oddHeadPre.next;
    }


    /**
     * 我发现不用创建临时的 dummyHead 节点
     * 直接 使用 head 节点返回就行
     * @param head
     * @return
     */
    public static ListNode oddEvenList2(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode odd = head;

        ListNode even = head.next;
        ListNode evenHead = even;

        ListNode cur = even.next;

        int index = 3;
        while (cur != null) {
            if (index % 2 == 1) {
                odd.next = cur;
                odd = cur;
            } else {
                even.next = cur;
                even = cur;
            }
            cur = cur.next;
            index++;
        }
        even.next = null;
        odd.next = evenHead;
        return head;
    }

    public static ListNode oddEvenList3(ListNode head) {
        if (head == null) return null;
        ListNode odd = head, even = head.next, evenHead = even;
        while (even != null && even.next != null){
            odd.next = odd.next.next;
            even.next = even.next.next;
            odd = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }

    public static void main(String[] args) {

        ListNode listNode1 = new ListNode(1);
        ListNode listNode2 = new ListNode(2);
        ListNode listNode3 = new ListNode(3);
        ListNode listNode4 = new ListNode(4);
        ListNode listNode5 = new ListNode(5);

        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode5;
        ListNode listNode6 = oddEvenList2(listNode1);
        ListNode listNode = oddEvenList(listNode1);
    }

}
