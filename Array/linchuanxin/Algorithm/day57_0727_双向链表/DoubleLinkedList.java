package day57_0727;

public class DoubleLinkedList<E> {

    private static class Node<E>{
        E item;
        Node<E> prev;
        Node<E> next;

        public Node(Node<E> prev,E item,Node<E> next){
            this.prev = prev;
            this.item = item;
            this.next = next;
        }

        private Node(){
            this(null,null,null);
        }
    }

    public DoubleLinkedList(){}

    //头结点
    Node<E> first;
    //尾结点
    Node<E> last;
    public int size;

    //添加数据 从尾部添加
    public void addLast(E e){
        Node<E> newNode = new Node<E>(last,e,null);
        Node<E> l = last;
        last = newNode;
        if(l == null){
            first = newNode;
        }else{
            l.next = newNode;
        }
        size++;
    }

    //添加数据
    public void add(E e){
        addLast(e);
    }


    //获取结点数据    10011--->>1-----01001
    private Node<E> node(int index){
        if (index < (size>>1)){
            Node<E> node = first;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        }else{
            Node<E> node = last;
            for (int i = size-1; i > index; i--) {
                node = node.prev;
            }
            return node;
        }
    }


    //查找数据
    public E get(int index){
        if(size < 0 || index > size)
            return null;
        return node(index).item;
    }


    public void add(int index,E e){
        if(index<0 || index > size)
            return;
        if(index==size){
            addLast(e);
        }else {
            Node<E> target = node(index);
            Node<E> pre = target.prev;
            Node<E> newNode = new Node<>(pre, e, target);
            if (pre == null) {
                first = newNode;
                target.prev = newNode;
            } else {
                pre.next = newNode;
                target.prev = newNode;
            }
        }
        size++;
    }

}

