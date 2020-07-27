package com.example.admin.myapplication.hash

/**
 *create by yx
 *on 2020/7/27
 */
//146. LRU缓存机制
class LRUCacheKotlin(capacity: Int) {

    class DLinkedNode(key: Int, value: Int) {
        val key: Int = key
        var value: Int = value
        var prev: DLinkedNode? = null
        var next: DLinkedNode? = null
    }

    private val map: HashMap<Int, DLinkedNode> = HashMap()
    private var head: DLinkedNode
    private var tail: DLinkedNode
    private var size = 0
    private var capacity: Int

    init {
        if (capacity <= 0) {
            this.capacity = 1
        } else {
            this.capacity = capacity
        }
        head = DLinkedNode(0, 0)
        tail = DLinkedNode(0, 0)
        head.next = tail
        tail.prev = head
    }


    fun get(key: Int): Int {
        var node = map[key]
        return if (node == null) {
            -1
        } else {
            removeNode(node)
            addNode(node)
            node.value
        }
    }

    fun put(key: Int, value: Int) {
        var node = map[key]
        if (node == null) {
            if (size == capacity) {
                val node = removeNode(tail.prev!!)
                map.remove(node.key)
                size--
            }
            val node = DLinkedNode(key, value)
            map[key] = node
            addNode(node)
            size++
        } else {
            removeNode(node)
            addNode(node)
            node.value = value
        }
    }

    private fun removeNode(node: DLinkedNode): DLinkedNode {
        val prev = node.prev
        val next = node.next
        prev?.next = next
        next?.prev = prev
        return node
    }

    private fun addNode(node: DLinkedNode) {
        val first = head.next
        head.next = node
        node.prev = head
        node.next = first
        first?.prev = node
    }
}