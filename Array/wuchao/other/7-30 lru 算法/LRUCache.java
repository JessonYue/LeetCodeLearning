package com.slow.lib.practice.lru;

import java.util.HashMap;

/**
 * @Author wuchao
 * @Date 2020/7/30-5:29 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
//自实现了一个hashmap ，效率没有用原生的高
//思路就是用一个双向链表，将hashMap中的元素以使用的先后顺序串联起来
//如果插入或取元素，就将这个节点放到头部，那么越靠近头部就是越是最近使用的，越靠近尾部就越是之前使用的
//当添加元素后，容量超过了阈值，则直接删除尾部的节点
class LRUCache {
    private LruCache<Integer,Integer> lru;
    public LRUCache(int capacity) {
        lru = new LruCache(capacity);
    }

    public int get(int key) {

        Integer value = lru.get(key);
        return value==null?-1:value;
    }

    public void put(int key, int value) {
        lru.put(key,value);
    }

    public class LruCache<K, V> {

        private int cacheCapacity;
        private Map<K, V> map = null;

        public LruCache(int cacheCapacity) {
            this.cacheCapacity = cacheCapacity;
            map = new Map<>();
        }

        public void put(K key, V value) {

            map.put(key, value);
        }

        public V get(K key) {
            return map.get(key);
        }

        public boolean removeEldestEntity(){
            return map.size>cacheCapacity;
        }

        public class Node<K, V> {
            //前置节点
            public Node<K, V> prev;
            //后继节点
            public Node<K, V> next;
            /**
             * before 和 after 是为了lru算法
             * 通过这两个指针将节点串成一个双向链表，这个双向链表和hash桶里的链表没有关系，这个链表是为了按操作时间的顺序组织所有的元素
             * 将最近使用的元素调整到链表的一端，将最不常使用的元素调整到链表的另一端，那么当缓存容量满了之后，既可以直接删掉最不常使用的元素
             * 避免了查找耗费性能
             */
            public Node<K, V> before;
            public Node<K, V> after;
            public K key;
            public V value;

            public Node(K key, V value) {
                this.key = key;
                this.value = value;
            }
        }

        public class Map<K, V> {
            private Node<K, V> eldest;
            private Node<K, V> youngest;
            private float loadFactor = 0.75f;
            private static final int MAX_CAPACITY = 1 << 30;
            private int capacity;
            private int size;
            private Node<K, V>[] entries;

            Map() {
                this(16);
            }

            @SuppressWarnings({"rawtypes", "unchecked"})
            Map(int initialCapacity) {
                int n = initialCapacity - 1;
                n |= n >>> 1;
                n |= n >>> 2;
                n |= n >>> 4;
                n |= n >>> 8;
                n |= n >>> 16;
                capacity = n < 0 ? 1 : n >= MAX_CAPACITY ? MAX_CAPACITY : n + 1;
                entries = (Node<K, V>[]) new Node[capacity];
                youngest = new Node<>(null, null);
                eldest = new Node<>(null, null);
                youngest.after = eldest;
                eldest.before = youngest;
            }

            int hash(K key) {
                return key.hashCode() & (entries.length - 1);
            }

            @SuppressWarnings({"rawtypes", "unchecked"})
            void resize(){
                int newCap = capacity <<1;
                Node<K,V>[] newTab = (Node<K, V>[])new Node[newCap];
                for(Node<K,V> item:entries){
                    if(item!=null){
                        Node<K,V> current = item.next;
                        if(current.next==null){
                            continue;
                        }
                        while(current.next!=null){
                            int index = current.key.hashCode()&(newTab.length-1);
                            Node<K,V> next = current.next;
                            current.prev.next = current.next;
                            current.next.prev = current.prev;
                            if(newTab[index] == null){
                                Node<K, V> head = new Node<>(null, null);
                                head.next = current;
                                current.prev = head;
                                newTab[index] = head;
                                Node<K, V> tail = new Node<>(null, null);
                                current.next = tail;
                                tail.prev = current;
                            } else {
                                Node<K,V> c = newTab[index].next;
                                while(c.next!=null){
                                    c = c.next;
                                }
                                c.prev.next = current;
                                current.prev = c.prev;
                                current.next = c;
                                c.prev = current;
                            }
                            current = next;
                        }
                    }

                }
                entries = newTab;
                capacity = newCap;
            }

            void put(K key, V value) {
                int index = hash(key);
                Node<K, V> entity = new Node<>(key, value);
                if (entries[index] != null) {
                    Node<K, V> head = entries[index];
                    Node<K, V> current = head.next;
                    while(current.next!=null){
                        if(current.key!=null&&current.key.hashCode()==key.hashCode()&&key.equals(current.key)){
                            current.value = value;
                            if(youngest.after!=current){
                                current.before.after = current.after;
                                current.after.before = current.before;
                                current.after = youngest.after;
                                youngest.after = current;
                                current.before = youngest;
                                current.after.before = current;
                            }
                            return;
                        }
                        current = current.next;
                    }
                    current.prev.next = entity;
                    entity.next = current;
                    entity.prev = current.prev;
                    current.prev = entity;
                } else {
                    Node<K, V> head = new Node<>(null, null);
                    head.next = entity;
                    entity.prev = head;
                    entries[index] = head;
                    Node<K, V> tail = new Node<>(null, null);
                    entity.next = tail;
                    tail.prev = entity;
                }
                if(youngest.after!=entity){
                    entity.after = youngest.after;
                    youngest.after = entity;
                    entity.before = youngest;
                    entity.after.before = entity;
                }
                size++;
                if(removeEldestEntity()){
                    removeEldest();
                }
                if(size>loadFactor*capacity){
                    resize();
                }
            }

            V get(K key) {
                int index = hash(key);
                Node<K, V> node = entries[index];
                if (node == null) {
                    return null;
                } else {
                    int keyHash = key.hashCode();
                    Node<K, V> current = node.next;
                    while (current.next != null) {
                        if (current.key.hashCode() == keyHash && key.equals(current.key)) {
                            if (current != youngest.after) {
                                current.after.before = current.before;
                                current.before.after = current.after;
                                current.after = youngest.after;
                                current.after.before = current;
                                youngest.after = current;
                                current.before = youngest;
                            }
                            return current.value;
                        }
                        current = current.next;
                    }
                    return null;
                }
            }

            void removeEldest() {
                if (eldest.before != youngest) {
                    Node<K, V> eldestNode = eldest.before;
                    eldestNode.before.after = eldest;
                    eldest.before = eldestNode.before;
                    eldestNode.prev.next = eldestNode.next;
                    eldestNode.next.prev = eldestNode.prev;
                    eldestNode.prev = null;
                    eldestNode.next = null;
                    eldestNode.before = null;
                    eldestNode.after = null;
                    size--;
                }
            }
        }

    }
}
