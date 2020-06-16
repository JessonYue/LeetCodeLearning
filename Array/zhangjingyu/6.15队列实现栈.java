public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);

        System.out.println(isPalindrome(listNode));
    }

    class MyStack {
        private Queue<Integer> a;//输入队列
        private Queue<Integer> b;//输出队列

        public MyStack() {
            a = new LinkedList<>();
            b = new LinkedList<>();
        }

        public void push(int x) {
            a.offer(x);
            // 将b队列中元素全部转给a队列
            while(!b.isEmpty())
                a.offer(b.poll());
            // 交换a和b,使得a队列没有在push()的时候始终为空队列
            Queue temp = a;
            a = b;
            b = temp;
        }

        public int pop() {
            return b.poll();
        }

        public int top() {
            return b.peek();
        }

        public boolean empty() {
            return b.isEmpty();
        }
    }





}