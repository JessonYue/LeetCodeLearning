package com.chow;

/**
 * 节点类
 */
public class Node {

    /** 节点的值 */
    int data;

    /** 下一点节点 */
    Node next;

    public Node(int data) {
        this.data = data;
        next = null;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Reference of the node with value = ");
        stringBuilder.append(data);
        return stringBuilder.toString();
    }
}
