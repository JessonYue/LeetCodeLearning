package com.chow;

/**
 * 用来存放节点
 */
public class MyNodeList {

    Node head = new Node(0);

    public void add(Node listnode) {
        Node tmp = head;
        while(tmp.next != null) {
            tmp = tmp.next;
        }
        tmp.next = listnode;
    }
}
