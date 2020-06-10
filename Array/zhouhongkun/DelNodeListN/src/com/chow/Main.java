package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        NodeList nodeList = new NodeList();
        nodeList.add(new Node(1));
        nodeList.add(new Node(61));
        nodeList.add(new Node(25));
        nodeList.add(new Node(7));
        nodeList.add(new Node(35));
        nodeList.add(new Node(16));

        Node headNode = nodeList.head;
        printNode(headNode);

        Node preNode = delNodeNOnce(headNode, 2);
        printNode(preNode);
    }

    //两次遍历方法来实现
    private static Node delNodeNTwice(Node node, int n){
        if(n <= 0){
            System.out.print("n不能为0，");
            return node;
        }
        Node resNode = node;
        Node pre = node;
        int index = 0;

        //第一次遍历得到链表的长度
        int nodeLength = 0;
        while (pre.next != null){
            pre = pre.next;
            nodeLength += 1;
        }
        if(n > nodeLength){
            System.out.print("n不能大于链表的长度，");
            return node;
        }
        //注意此时pre遍历到了尾节点，所以要重新指向头节点
        pre = resNode;
        //第二次从头开始遍历，去删除倒数第n个节点，即正数nodeLength-n个节点
        while (index != nodeLength-n){
            pre = pre.next;
            index++;
        }
        //删除倒数第n个节点，分两步完成，此处可以合成一步 pre.next = pre.next.next;
        Node tmp = pre.next;
        pre.next = tmp.next;
        return resNode;
    }

    //一次遍历算法
    private static Node delNodeNOnce(Node node, int n){
        if(n <= 0){
            System.out.print("n不能为0，");
            return node;
        }

        Node resNode = node;
        Node first = resNode;
        Node second = resNode;
        //第一个指针先往后移动n个节点
        for(int i=0; i<n; i++){
            first = first.next;
        }

        //此时第二个指针开始往后移动，且和第一个指针保持n个长度，当第一个指针到达尾节点时，第二个指针刚好到达倒数第n个节点位置
        while (first.next != null){
            first = first.next;
            second = second.next;
        }
        //删除倒数第n个节点
        second.next = second.next.next;
        return resNode;
    }

    //打印链表
    private static void printNode(Node headNode){
        StringBuilder builder = new StringBuilder();
        while (headNode.next != null){
            builder.append(headNode.data);
            builder.append("->");
            headNode = headNode.next;
        }
        builder.append(headNode.data);
        System.out.println(builder.toString());
    }
}
