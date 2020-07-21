package com.slow.lib.practice.tree

/**
 * @Author wuchao
 * @Date 2020/7/13-10:15 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class BSTConvertToLinkedList {
    class TreeNode(var `val`: Int) {
        var left: TreeNode? = null
        var right: TreeNode? = null
    }

    fun convertBiNode(root: TreeNode?): TreeNode? {
        if(root==null){
            return null
        }
        var leftHead = convertBiNode(root.left)
        root.left = null
        var head = leftHead
        if(head==null){
            head = root
        } else {
            while(leftHead?.right!=null){
                leftHead = leftHead.right
            }
            leftHead?.right = root
        }
        root.right = convertBiNode(root.right)
        return head
    }
}