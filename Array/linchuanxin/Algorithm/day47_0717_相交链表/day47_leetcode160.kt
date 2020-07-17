package day47_0717


class ListNode(var `val`: Int) {
         var next: ListNode? = null
     }


fun getIntersectionNode(headA:ListNode?, headB:ListNode?):ListNode? {
    var p: ListNode? = headA
    var q:ListNode? = headB

    while (p != q){
        if (p != null)
            p = p.next
        else
            p = headB
        if (q != null)
            q = q.next
        else
            q = headA
    }
    return p
}