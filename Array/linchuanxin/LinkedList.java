/**
 * Created by linchuanxin on 2020/05/31
 */
 
public class LinkedList<E> {
    /**
     * ���
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
 
    //ͷ�ڵ�
    Node<E> first;
    //β�ڵ�
    Node<E> last;
    //��С
    int size;
 
    /**
     * ������������
     */
    public void add(E e) {
        linkLast(e);
    }
 
    /**
     * ��ӵ����
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
     * ����λ��
     */
    public E get(int index){
        if(index<0 || index>size){
            return null;
        }
        return node(index).item;
    }
    /**
     * ��ȡindexλ���ϵĽڵ�
     */
    private Node<E> node(int index){
 
        //���index�����������ǰ�벿��
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
     * ���������indexλ��
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
     * ɾ��Ԫ��
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