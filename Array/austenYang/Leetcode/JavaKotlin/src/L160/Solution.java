package L160;

import Base.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution {

    /**
     * 思路：1
     * <p>
     * 1. headA ,headB 链表长度 对应 l1 , l2 。
     * 2. 长链表 -> l1 ,短 链表 --> l2，上长链表先 走 (l1-l2).
     * 3. 两个链表一起向前进，相遇时必定是两个链表的交点
     *
     * @param headA
     * @param headB
     * @return
     */
    public ListNode getIntersectionNod1(ListNode headA, ListNode headB) {
        ListNode headATemp = headA;
        ListNode headBTemp = headB;
        int l1 = 0;
        while (headATemp != null) {
            l1++;
            headATemp = headATemp.next;
        }
        int l2 = 0;
        while (headBTemp != null) {
            l2++;
            headBTemp = headBTemp.next;
        }
        int distance;
        if (l1 < l2) {
            headATemp = headB;
            headBTemp = headA;
            distance = l2 - l1;
        } else {
            headATemp = headA;
            headBTemp = headB;
            distance = l1 - l2;
        }

        while (distance > 0) {
            headATemp = headATemp.next;
            distance--;
        }
        while (headATemp != null && headBTemp != null) {
            if (headATemp == headBTemp) {
                return headATemp;
            }
            headATemp = headATemp.next;
            headBTemp = headBTemp.next;
        }
        return null;
    }

    /**
     * 思路：2
     * 1. 用 容器 ，现将 headA 遍历放入 容器
     * 2. 编译 head b ， 容器中存在 b 上的节点，且是第一个即为交点
     *
     * @param headA
     * @param headB
     * @return
     */
    public ListNode getIntersectionNod2(ListNode headA, ListNode headB) {
        Set<ListNode> container = new HashSet<>();
        for (ListNode pA = headA; pA != null; pA = pA.next) {
            container.add(pA);
        }
        for (ListNode pB = headB; pB != null; pB = pB.next) {
            if (container.contains(pB)) {
                return pB;
            }
        }
        return null;

    }

    /**
     * 思路：3
     * 双指针发
     *
     *
     *
     * @param headA
     * @param headB
     * @return
     */
    public ListNode getIntersectionNod3(ListNode headA, ListNode headB) {
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != null || pB != null) {
            if (pA == pB) {
                return pA;
            }
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }
        return null;
    }

    public static void main(String[] args) {

    }
}
