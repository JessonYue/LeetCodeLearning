package algorithms4.chapter_1;

import org.omg.CORBA.Object;

import java.util.Iterator;

public class ResizingArrayQueue<Item>  implements Iterable<Item>{
    private Item[] a;
    private int N = 0;

    public ResizingArrayQueue(int capacity) {
        a = (Item[]) new Object[capacity];
    }

    void enqueue(Item item) {

    }

    Item dequeue() {
        return null;
    }

    boolean isEmpty() {
        return N == 0;
    }

    int size() {
        return N;
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
