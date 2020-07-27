package L101

import Base.TreeNode
import apple.laf.JRSUIUtils
import java.util.*


fun isSymmetric1(root: TreeNode): Boolean {
    return isMirror(root, root)
}


private fun isMirror(t1: TreeNode?, t2: TreeNode?): Boolean {
    if (t1 == null && t2 == null) return true
    if (t1 == null || t2 == null) return false

    return t1.`val` == t2.`val`
            && isMirror(t1.left, t2.right)
            && isMirror(t1.right, t2.left)

}

/**
 * 检查树的对对称性
 *
 */
fun isSymmetric2(root: TreeNode): Boolean {
    val queue: Queue<TreeNode> = LinkedList()
    queue.offer(root)
    queue.offer(root)

    while (!queue.isEmpty()) {
        val t1 = queue.poll()
        val t2 = queue.poll()

        if (t1 == null && t2 == null) continue
        if (t1 == null || t2 == null) return false

        if (t1.`val` != t2.`val`) return false

        queue.offer(t1.left)
        queue.offer(t2.right)
        queue.offer(t1.right)
        queue.offer(t2.left)
    }
    return true
}

fun main() {
    println(isSymmetric1(TreeNode.mkTree("[1,2,2,null,3,null,3]")))
    println(isSymmetric2(TreeNode.mkTree("[1,2,2,null,3,null,3]")))

}