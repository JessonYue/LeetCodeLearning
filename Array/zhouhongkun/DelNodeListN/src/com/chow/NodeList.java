package com.chow;

public class NodeList {
    Node head = new Node(0);

    void add(Node node){
        Node tmp = head;
        while (tmp.next != null){
            tmp = tmp.next;
        }
        tmp.next = node;
    }
}
