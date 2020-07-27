package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/27-10:49 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class SortLinkedList {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun sortList(head: ListNode?): ListNode? {
        if(head==null) return null
        var dummy = ListNode(-1)
        dummy.next = head
        var temp = dummy
        var length = 0
        while(temp.next!=null){
            temp = temp.next!!
            length++
        }
        var i=1
        while(i<length){
            temp = dummy
            var j=0
            while(j<length-i){
                var leftHead = temp.next
                var rightHead = leftHead
                var leftEnd=0
                var rightEnd=0
                while(rightEnd<i){
                    rightHead = rightHead?.next
                    rightEnd++
                }
                rightEnd=0
                while(leftEnd<i&&rightEnd<i&&rightHead!=null){
                    if(leftHead!!.`val`<rightHead.`val`){
                        temp.next = leftHead
                        leftHead = leftHead.next
                        leftEnd++
                    } else {
                        temp.next = rightHead
                        rightHead = rightHead.next
                        rightEnd++
                    }
                    temp = temp.next!!
                }
                while(leftEnd<i){
                    temp.next = leftHead
                    leftHead = leftHead?.next
                    temp = temp.next!!
                    leftEnd++
                }
                while(rightEnd<i&&rightHead!=null){
                    temp.next = rightHead
                    rightHead = rightHead.next
                    temp = temp.next!!
                    rightEnd++
                }
                temp.next = rightHead
                j += i.shl(1)
            }
            i = i.shl(1)
        }
        return dummy.next
    }
}