package leetCode;

import java.util.HashMap;

class LRUCache {

    //LRU的实现需要一个HashMap+ DoubleLinkedList
    //HashMap用作cache ,判断是否存在该节点，DLinkedList来实现node的移动
    //注意的点：1.动态扩容 2.多进程并发(暂不考虑)
    //tips：DLinkedList中可以事先定义好head和tail

    //step1:定义好DLinkedList的实现
    //step2：LRUCache 需要包含的cache ,size，capacity, (head，tail)
    // step3：需要实现的api:
    //LRUCache---> get,put
    //DLinkList---》remove ,moveToHead,removeTail,addToHead


    //step2
    private HashMap<Integer, DLinkedListNode> cache = new HashMap<>();
    private int size;
    private int capacity;
    private DLinkedListNode head, tail;


    public LRUCache(int capacity) {
        size = 0;
        this.capacity = capacity;
        this.head = new DLinkedListNode();
        this.tail = new DLinkedListNode();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        DLinkedListNode node = cache.get(key);
        if (node == null) {
            return -1;
        }

        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        DLinkedListNode node = cache.get(key);
        if (node != null) {
            node.value = value;
            node.key = key;
            moveToHead(node);
        } else {
            node = new DLinkedListNode(key, value);
            addToHead(node);
            cache.put(key, node);
            size++;
            if (size > capacity) {
                DLinkedListNode realTail = removeTail();
                cache.remove(realTail.key);
                size--;
            }
        }

    }

    //step1
    public class DLinkedListNode {
        private DLinkedListNode prev;
        private DLinkedListNode next;
        private int value;
        private int key;

        public DLinkedListNode(int key, int value) {
            this.value = value;
            this.key = key;
        }

        public DLinkedListNode() {
        }
    }

    public DLinkedListNode removeNode(DLinkedListNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        return node;
    }

    public DLinkedListNode removeTail() {
        DLinkedListNode realTail = tail.prev;
        removeNode(realTail);
        return realTail;
    }

    public DLinkedListNode moveToHead(DLinkedListNode node) {
        removeNode(node);
        addToHead(node);
        return node;
    }

    private void addToHead(DLinkedListNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }


}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
