public class day25 {
    public static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public int hasCycle(Node head) {
            int count = -1;
            Node slowNode = head;
            Node fastNode = head;
            if (slowNode.next == null || fastNode.next == null) {
                return -1;
            }
            for (; ; ) {
                slowNode = slowNode.next;
                fastNode = fastNode.next.next;
                if (slowNode == fastNode) {
                    return count;
                } else if (fastNode == null) {
                    return count;
                } else {
                    count++;
                }
            }

        }

    }

    public static void main(String[] args) {
        Node node1 = new Node(3);
//        Node node2 = new Node(2);
//        node1.setNext(node2);
//        node2.setNext(node1);
//        Node node3 = new Node(0);
//        node2.setNext(node3);
//        Node node4 = new Node(4);
//        node3.setNext(node4);
//        node4.setNext(node2);
        System.out.println("=====" + node1.hasCycle(node1));
    }

}
