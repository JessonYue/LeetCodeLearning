package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/2
 * @describe
 */
class day32 {

    class ListNode {
        var data = 0;
        var next: ListNode? = null;
    }

    class TreeNode {
        var data = 0;
        var left: TreeNode? = null;
        var right: TreeNode? = null;
    }

    fun FindMidNode(head: ListNode, prevs: ListNode): ListNode {
        var fast = head;
        var slow = head;
        var prev:ListNode? = null;
        while (fast != null && fast.next != null) {
            fast = fast.next!!.next!!;
            prev = slow;
            slow = slow.next!!;
        }

        return slow;
    }

    fun sortedListToBST(head: ListNode): TreeNode? {

        var left: ListNode? = null;
        var midNode: ListNode?=null;
        var right: ListNode?=null;
        midNode = left?.let { FindMidNode(head, it) };
        var root: TreeNode? = null;

        if (root != null) {
            if (midNode != null) {
                root.data = midNode.data
            }
        };
        if (left != null) {
            left.next = null;
            if (root != null) {
                root.left = sortedListToBST(head)
            };
        }
        if (midNode != null) {
            if (midNode.next != null) {
                if (root != null) {
                    root.right = sortedListToBST(midNode.next!!)
                };
            }
        }
        return root;
    }
}
