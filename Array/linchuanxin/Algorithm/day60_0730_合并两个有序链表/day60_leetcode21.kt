package day60_0730

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}


fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
    var dump:ListNode? = ListNode(-1)
    var dumpHelper:ListNode? = dump
    var index_l:ListNode? = l1
    var index_r:ListNode? = l2
    while (index_l!=null && index_r!=null){
        if (index_l.`val` <= index_r.`val`){
            dumpHelper?.next = index_l
            index_l = index_l.next
            dumpHelper = dumpHelper?.next
        }else{
            dumpHelper?.next = index_r
            index_r = index_r.next
            dumpHelper = dumpHelper?.next
        }
    }
    if(index_l == null)
        dumpHelper?.next = index_r
    if(index_r == null)
        dumpHelper?.next = index_l
    return dump?.next
}
