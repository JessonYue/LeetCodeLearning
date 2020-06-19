package com.slow.lib.practice.queue

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/6/18-2:57 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MaxQueue {
    val queue:Queue<Int> = LinkedList()
    val temp:Queue<Int> = LinkedList()
    var max = -1
    fun max_value(): Int {
        return max
    }

    fun push_back(value: Int) {
        queue.offer(value)
        if(value>max){
            max = value
        }
    }

    fun pop_front(): Int {
        val pop = queue.poll()
        if(pop == max){
            max = -1
            while(!queue.isEmpty()){
                val top = queue.poll()
                temp.offer(queue.poll())
                if(top>max){
                    max = top
                }
            }
            while(!temp.isEmpty()){
                queue.offer(temp.poll())
            }
        }
        return pop
    }
}