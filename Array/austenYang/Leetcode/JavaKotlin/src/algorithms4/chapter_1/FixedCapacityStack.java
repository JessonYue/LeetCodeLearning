package algorithms4.chapter_1;

import org.omg.CORBA.Object;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class FixedCapacityStack<Item> implements Iterable<Item>{
    private Item[] arrays;
    private int N;

    public FixedCapacityStack(int cap) {
        arrays = (Item[]) new Object[cap];
    }

    public void push(Item item) {
        if (N == arrays.length) resize(2 * arrays.length);
        arrays[N++] = item;
    }

    /**
     * 动态缩容：容量 N 是否小于 数组长度的 1/4 。
     * 在数组长度被减半后，数组的状态约为半满，在下次需要改变数组大小之前
     * 仍然能够进行多次 push 和 pop 操作。
     * 不至于，减半后马上又扩容。
     * @return
     */
    public Item pop() {
        if (!isEmpty()) {
            throw new UnsupportedOperationException("is Empty!");
        }
        Item item = arrays[--N];
        arrays[N] = null;
        if (N > 0 && N == arrays.length / 4) resize(arrays.length / 2);
        return item;
    }


    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }


    private void resize(int max) {
        Item[] oldArrays = arrays;

        Item[] newArrays = (Item[]) new Object[max];
        for (int i = 0; i < N; i++) {
            newArrays[i] = oldArrays[i];
        }
        arrays = newArrays;
    }


    @Override
    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item>{
        private int i = N;
        @Override
        public boolean hasNext() {
            return i > 0;
        }

        @Override
        public Item next() {
            if (i == 0) throw new NoSuchElementException("Stack is Empty!");
            return arrays[--i];
        }

    }
}
