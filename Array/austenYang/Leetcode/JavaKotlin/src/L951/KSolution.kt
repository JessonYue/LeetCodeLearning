package L951

import Base.TreeNode

fun flipEquiv(root1: TreeNode?, root2: TreeNode?): Boolean = dsf(root1, root2)

private fun dsf(t1: TreeNode?, t2: TreeNode?): Boolean {
    // 两棵树都是 null，这说明我们深度优先遍历，跑到了叶子结点的下面一层
    // 比方说是图中 7 这个叶子节点，叶子节点的左右两棵树都是 null 也就是看做是相等，返回 true
    if (t1 == null && t2 == null) return true

    if (t1 == null || t2 == null) return false

    if (t1.`val` != t2.`val`) return false

    return (dsf(t1.left, t2.left) && dsf(t1.right, t2.right)) ||
            (dsf(t1.left, t2.right) && dsf(t1.right, t2.left))


}

fun main() {

}