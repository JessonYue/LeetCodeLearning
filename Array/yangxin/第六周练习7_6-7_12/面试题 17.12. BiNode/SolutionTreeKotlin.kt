package com.example.admin.myapplication.tree

/**
 *create by yx
 *on 2020/7/12
 */

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class SolutionTreeKotlin {

    /**
     * 面试题 17.12. BiNode
     * 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
     * 返回转换后的单向链表的头节点。
     */
    fun convertBiNode(root: TreeNode?): TreeNode? {
        if (root == null) {
            return null
        }
        val head = TreeNode(-1)
        inorder(root, head)
        return head.right
    }

    fun inorder(root: TreeNode?, pre:TreeNode):TreeNode {
        var tmp = pre
        if (root != null) {
            tmp = inorder(root.left, tmp)
            root.left = null
            tmp.right = root
            tmp = inorder(root.right, root)
        }

        return tmp
    }
}