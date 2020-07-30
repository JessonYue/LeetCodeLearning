package com.slow.lib.practice.lru

import java.util.*


/**
 * @Author wuchao
 * @Date 2020/7/30-6:43 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class LRUCache(var capacity: Int) {
    class LRUCache(var capacity: Int) {
        var cacheMap:HashMap<Int,Node<Int,Int>> = HashMap(capacity)
        var head:Node<Int,Int> = Node(null,null)
        var tail:Node<Int,Int> = Node(null,null)
        init {
            head.after = tail
            tail.before = head
        }

        inner class Node<K,V>(var key:K?, var value:V?){
            var before:Node<K,V>?=null
            var after:Node<K,V>?=null
        }

        fun get(key: Int): Int {
            val node = cacheMap[key]
            val value = node?.value?:-1
            if(value!=-1){
                if(head.after!=node){
                    val before = node?.before
                    before?.after = node?.after
                    node?.after?.before = before
                    val after = head.after
                    head.after = node
                    node?.before = head
                    node?.after = after
                    after?.before = node
                }
            }
            return value
        }

        fun put(key: Int, value: Int) {
            val isContainsKey = cacheMap.containsKey(key)
            val entity = cacheMap.getOrDefault(key,Node(key,value))
            entity.value = value
            cacheMap[key] = entity
            if(!isContainsKey){
                val after = head.after
                head.after = entity
                entity.before = head
                entity.after = after
                after?.before = entity
            } else {
                if(head.after!=entity){
                    val before = entity?.before
                    before?.after = entity?.after
                    entity?.after?.before = before
                    val after = head.after
                    head.after = entity
                    entity?.before = head
                    entity?.after = after
                    after?.before = entity
                }

            }
            if(cacheMap.size>capacity) {
                removeEldest()
            }
        }

        fun removeEldest() {
            val current = tail.before
            current?.before?.after = tail
            tail.before = current?.before
            cacheMap.remove(current?.key!!)
        }


    }


}