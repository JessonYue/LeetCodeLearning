public class day26 {

    public static class LinkedNode {
        int data;
        LinkedNode next;

        public LinkedNode(int data) {
            this.data = data;
        }

        public LinkedNode deleteNode(int data, LinkedNode node) {
            LinkedNode deleteNode = node;
            LinkedNode beforeNode = null;
            for (int i = 0; i < 4; i++) {
                if (deleteNode.data == data) {
                    beforeNode.next = deleteNode.next;
                    break;
                } else {
                    beforeNode = deleteNode;
                    deleteNode = deleteNode.next;
                }
            }
            return beforeNode;
        }
    }

    public static void main(String[] args) {
        LinkedNode node1 = new LinkedNode(4);
        LinkedNode node2 = new LinkedNode(5);
        node1.next = node2;
        LinkedNode node3 = new LinkedNode(1);
        node2.next = node3;
        LinkedNode node4 = new LinkedNode(9);
        node3.next = node4;
        LinkedNode finalNode = node1.deleteNode(5, node1);
        for (int i = 0; i < 4; i++) {
            System.out.println("=====" + finalNode.data);
            if (finalNode.next != null)
                finalNode = finalNode.next;
        }

    }
}
