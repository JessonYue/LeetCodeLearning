public class day30 {

    static class LinkedNode{
        int data =0;
        LinkedNode next = null;

        public LinkedNode(int data) {
            this.data = data;
        }
    }

    public static LinkedNode reverseList(LinkedNode head) {
        LinkedNode node = null;
        LinkedNode before = null;
        LinkedNode node1 = head;
        for (int i = 0; i < 5; ++i) {
            LinkedNode node2 = node1;
            node1 = node1.next;
            node2.next = null;
            if (node == null&&before == null){
                node = node2;
            } else {
                before = node;
                node2.next = node;
                node = node2;
            }
        }
        return node;
    }

    public static void main(String[] args) {
        LinkedNode node1 = new LinkedNode(1);
        LinkedNode node2 = new LinkedNode(2);
        node1.next = node2;
        LinkedNode node3 = new LinkedNode(3);
        node2.next = node3;
        LinkedNode node4 = new LinkedNode(4);
        node3.next = node4;
        LinkedNode node5 = new LinkedNode(5);
        node4.next = node5;
        LinkedNode node = reverseList(node1);

        for (int i = 0; i < 5; ++i) {
            System.out.println("====="+ node.data);
            node = node.next;
        }
    }
}
