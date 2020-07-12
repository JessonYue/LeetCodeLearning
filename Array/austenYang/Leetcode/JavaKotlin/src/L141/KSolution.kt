package L141

<<<<<<< HEAD
import Base.ListNode
=======
import DataStructure.ListNode
import java.util.*
>>>>>>> 5b01aa919a061097fc6b72887bda0b14d751cb42

fun hasCycle1(head: ListNode?): Boolean {
    var h = head
    val container = HashSet<ListNode>()
    while (h != null) {
        if (container.contains(h)) {
            return true
        } else {
            container.add(h)
        }
        h = h.next
    }
    return false
}

fun hasCycle2(head: ListNode?): Boolean {
    if (head?.next == null) {
        return false
    }

    var slow: ListNode? = head
    var fast: ListNode? = head.next

    while (slow !== fast) {
        if (fast?.next == null) {
            return false
        }
        slow = slow?.next
        fast = fast?.next?.next
    }

    return true
}
