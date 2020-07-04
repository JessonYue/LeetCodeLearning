package staudy
class Algorithm7_2 {

    fun kthToLast(head:ListNode?,k:Int):Int?{
        var a = head
        var p = a
        for (i in 1..k){
            p = p?.next
        }

        while (p != null){
            p = p.next
            a = a?.next
        }
        return a?.`val`
    }
}

class ListNode(var `val`: Int,var next: ListNode? = null)