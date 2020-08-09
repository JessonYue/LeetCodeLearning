package algorithms4.chapter_1;

import org.omg.CORBA.Object;

import java.util.Iterator;

/**
 * 背包
 *
 * @param <Item>
 */
public class Bag<Item> implements Iterable<Item> {
    private Item[] items;
    public Bag() {
        items = (Item[]) new Object[10];
    }

    public void add(Item item) {

    }

    public boolean isEmpty() {
        return false;
    }

    public int size() {
        return 0;
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
