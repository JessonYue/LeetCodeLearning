package LInterview02_07

import Base.ListNode


fun getIntersectionNode1(headA: ListNode?, headB: ListNode?): ListNode? {
    var t1 = headA
    var t2 = headB

    while (t1 !== t2) {
        if (t1 == null)
            t1 = headB
        else
            t1 = t1.next

        if (t2 == null)
            t2 = headA
        else
            t2 = t2.next
    }
    return t1
}


fun getIntersectionNode2(headA: ListNode?, headB: ListNode?): ListNode? {
    val set = hashSetOf<ListNode>()
    var pa = headA
    while (pa != null) {
        set.add(pa)
        pa = pa.next
    }
    var pb = headB
    while (pb != null) {
        if (set.contains(pb)) {
            return pb
        }
        pb = pb.next
    }
    return null

}

fun getIntersectionNode3(headA: ListNode?, headB: ListNode?): ListNode? {
    var headALength = 0
    var headBLength = 0

    var pa = headA
    var pb = headB
    var pa1 = headA
    var pb1 = headB

    while (pa != null) {
        headALength++
        pa = pa.next
    }
    while (pb != null) {
        headBLength++
        pb = pb.next
    }
    val distance: Int
    if (headALength >= headBLength) {
        distance = headALength - headBLength
        while (distance > 0) {
            pa1 = pa1?.next
        }
    } else {
        distance = headBLength - headALength
        while (distance > 0) {
            pb1 = pb1?.next
        }
    }
    while (headA != null && headB != null) {
        if (headA === headB) {
            return headA
        }
    }

    return null


}

fun main() {

}