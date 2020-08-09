package algorithms4.chapter_1;

import java.util.Iterator;

public class Stack<Item> implements Iterable<Item>{
    private Item[] items;
    public Stack() {
        items = (Item[]) new Object[10];
    }
    void push(Item item){

    }
    Item pop(){
        return null;
    }
    boolean isEmpty(){
        return false;
    }

    int size(){
return 0;
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
