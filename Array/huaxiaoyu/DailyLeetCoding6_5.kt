import org.junit.Test

class DailyLeetCoding6_5 {

    //2020.06.5
    //面试题 02.07. 链表相交 //https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
    //给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
    //示例 1：
    //输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    //输出：Reference of the node with value = 8
    //输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

    //示例 2：
    //输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
    //输出：Reference of the node with value = 2
    //输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
    //
    //示例 3：
    //输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
    //输出：null
    //输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
    //解释：这两个链表不相交，因此返回 null。
    //注意：
    //如果两个链表没有交点，返回 null 。
    //在返回结果后，两个链表仍须保持原有的结构。
    //可假定整个链表结构中没有循环。
    //程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
    class ListNode constructor(var value: Int) {
        var node: ListNode? = null;
    }

    @Test
    fun text(headA: ListNode?, headB: ListNode?): ListNode? {
        if (headA == null || headB == null) return null;

        var pA=headA
        var pB=headB

        //总的思路: 如果两个链表相交,则切换运算一定会相等
        // 比如   2763
        //      08563
        // 连个链表相交于后半部分,将两个链表相连,63一定会出现,
        //276308563
        //085632763
        //相连后长度一样,并且相交的部分一定会在尾部出现

        while(pA!=pB){
            //如果链表1的A和链表2的B不相等,则next;
            // 如果相等则返回;
            // 如果为空,则表示链表到头了
            pA=pA?.node?:headB
            pB=pB?.node?:headA
        }
        return pA
    }
}