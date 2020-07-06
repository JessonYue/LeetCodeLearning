package staudy

class Algorithm6_24 {

    fun hashSolution(head: ListNode?):Boolean{
        var a = head
        val set = LinkedHashSet<ListNode>()
        while (a != null){
           if (set.contains(a)){
               return true
           }
            set.add(a)
            a = a.next
        }

        return false
    }
}

class ListNode(var `val`: Int, var next: ListNode?) {

}