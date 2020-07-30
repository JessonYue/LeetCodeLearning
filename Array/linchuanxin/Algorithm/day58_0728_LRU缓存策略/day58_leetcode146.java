package day58_0728;

import java.util.HashMap;

public class LRUCache {

    /*
    *
    *
    * int get(int key){
    *   if(key补存在){
    *       return -1;
    *   }else{
    *       提到开头
    *       return val;
    *   }
    * }
    *
    *
    * void put(int key, int value){
    *
    *   Node e = new Node(key value);
    *   if(key已存在){
    *       删除旧数据
    *       将新结点插在开头
    *   }else{
    *       判断满
    *       if(cache){
    *           删除最后一个数据
    *           删除map映射键值
    *       }
    *       将新结点插在开头
    *       map新建键值关系
    *   }
    * }
    *
    *
    * */


    private class Node{
        private int key;
        private int value;
        private Node pre;
        private Node next;
        public Node(){};
        public Node(int key, int value){
            this.key = key;
            this.value = value;
        }
    }
    private Node dummyHead = new Node();
    private Node dummyTail = new Node();
    private int capacity;
    private int size;
    private HashMap<Integer,Node> hashMap = new HashMap<>();

    private void add(Node node){
        Node originHead = dummyHead.next;
        dummyHead.next = node;
        node.pre = dummyHead;
        node.next = originHead;
        originHead.pre = node;
    }

    private void del(Node node){
        Node preNode = node.pre;
        Node nextNode = node.next;
        preNode.next = nextNode;
        nextNode.pre = preNode;
        node.pre = null;
        node.next = null;
    }

    public LRUCache(int capacity) {
        dummyHead.next = dummyTail;
        dummyTail.pre = dummyHead;
        this.capacity = capacity;
        size = 0;
    }

    public int get(int key) {
        /*if(key补存在){
         *       return -1;
         *   }else{
         *       提到开头
         *       return val;
         *   }*/
        Node node = hashMap.get(key);
        if(node==null)
            return -1;
        del(node);
        add(node);
        return node.value;
    }

    public void put(int key, int value) {
        /*    *   Node e = new Node(key value);
         *   if(key已存在){
         *       删除旧数据
         *       将新结点插在开头
         *   }else{
         *       判断满
         *       if(cache){
         *           删除最后一个数据
         *           删除map映射键值
         *       }
         *       将新结点插在开头
         *       map新建键值关系
         *   }*/
//        Node e = new Node(key,value);
//        Node node = hashMap.get(key);
//        if(node != null){
//            del(node);
//            add(e);
//        }else{
//            if(size >= capacity){
//                del(node);
//                hashMap.remove(key);
//            }
//            add(e);
//            hashMap.put(key,e);
//            size++;
//        }
        Node node = hashMap.get(key);
        if(null != node){
            node.value = value;
            del(node);
            add(node);
        }else{
            if(size < capacity){
                size++;
            }else{
                Node delNode = dummyTail.pre;
                hashMap.remove(delNode.key);
                del(delNode);
            }
            Node newNode = new Node(key, value);
            add(newNode);
            hashMap.put(key, newNode);
        }
    }
}
