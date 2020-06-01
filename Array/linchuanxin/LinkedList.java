/**
 * Created by linchuanxin on 2020/05/31
 */
 
public class LinkedList<E> {
    /**
     * 结点
     */
    private static class Node<E> {
        E item;
        Node<E> prev;
        Node<E> next;
 
        public Node(Node<E> prev, E item, Node<E> next) {
            this.item = item;
            this.prev = prev;
            this.next = next;
        }
    }
 
    public LinkedList() {
 
    }
 
    //头节点
    Node<E> first;
    //尾节点
    Node<E> last;
    //大小
    int size;
 
    /**
     * 添加数据在最后
     */
    public void add(E e) {
        linkLast(e);
    }
 
    /**
     * 添加到最后
     * @param e
     */
    private void linkLast(E e) {
        Node<E> newNode = new Node<E>(last, e, null);
        Node<E> l = last;
        last=newNode;
 
        if(l==null){
            first=newNode;
        }else {
            l.next = newNode;
        }
        size++;
    }
    /**
     * 查找位置
     */
    public E get(int index){
        if(index<0 || index>size){
            return null;
        }
        return node(index).item;
    }
    /**
     * 获取index位置上的节点
     */
    private Node<E> node(int index){
 
        //如果index在整个链表的前半部分
        if(index<(size>>1)){   //1000 100   10
            Node<E> node=first;
            for (int i = 0; i < index; i++) {
                node=node.next;
            }
            return node;
        }else{
            Node<E> node=last;
            for (int i = size-1; i > index; i--) {
                node=node.prev;
            }
            return node;
        }
 
 
    }
 
    /**
     * 添加数据在index位置
     */
    public void add(int index,E e) {
        if(index<0 || index>size){
            return ;
        }
        if(index==size){
            linkLast(e);
        }else{
            Node<E> target=node(index);//  index=2
            Node<E> pre=target.prev;
            Node<E> newNode=new Node<E>(pre,e,target);
 
            if(pre==null){
                first=newNode;
                target.prev = newNode;//4
            }else {
                pre.next = newNode;//3
                target.prev = newNode;//4
            }
            size++;
        }
 
    }
 
    /**
     * 删除元素
     */
    public void remove(int index){
        Node<E> target=node(index);
        unlinkNode(target);
    }
 
    private void unlinkNode(Node<E> p) {//index=2
        Node<E> pre=p.prev;
        Node<E> next=p.next;
        if(pre==null){
            first=p.next;
        }else{
            pre.next=p.next;
        }
        if(next==null){
            last=p.prev;
        }else{
            next.prev=p.prev;
        }
        size--;
    }
 
}