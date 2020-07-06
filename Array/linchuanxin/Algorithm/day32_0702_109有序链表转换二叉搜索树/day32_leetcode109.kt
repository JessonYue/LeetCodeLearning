package day32


  class ListNode(var `val`: Int) {
      var next: ListNode? = null
  }


  class TreeNode(var `val`: Int) {
      var left: TreeNode? = null
      var right: TreeNode? = null
  }

class Solution {

    fun findMidNode(head: ListNode?):ListNode?{
        var pre:ListNode? = null
        var fast:ListNode? = head
        var slow:ListNode? = head
        while (fast !=null && fast.next!=null){
            pre = slow
            slow = slow?.next;
            fast = fast.next?.next
        }
        if(pre != null){
            pre.next = null
        }
        return slow
    }


    fun sortedListToBST(head: ListNode?): TreeNode? {
        if (head == null)
            return null
        var midNode:ListNode? = findMidNode(head)
        var treeNode:TreeNode = TreeNode(midNode!!.`val`)
        if(head == midNode){
            return treeNode
        }
        treeNode.left = sortedListToBST(head)
        treeNode.right = sortedListToBST(midNode.next)
        return treeNode
    }
}