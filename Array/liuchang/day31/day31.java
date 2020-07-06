public class day31 {

    static class LinkedNode {
        int data = 0;
        LinkedNode next = null;

        public LinkedNode(int data) {
            this.data = data;
        }
    }

    public static int kthToLast(LinkedNode head, int k, int size) {
        int count = 0;
        while (head.next != null) {
            if (count == size - k) {
                return head.data;
            } else {
                head = head.next;
            }
            count++;
        }
        return -1;
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
        System.out.println("=====" + kthToLast(node1, 2, 5));
    }
}
