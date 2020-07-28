package com.example.admin.myapplication.hash;

import java.util.LinkedList;

/**
 * create by yx
 * on 2020/7/27
 */
//146. LRU缓存机制
public class LRUCache {
    private class Entry {
        int key;
        int value;

        public Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    LinkedList<Entry> list;
    int capacity;
    int size = 0;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        list = new LinkedList();
    }

    public int get(int key) {
        Entry entry = findByKey(key);
        if (entry != null) {
            list.remove(entry);
            list.addFirst(entry);
            return entry.value;
        } else {
            return -1;
        }
    }

    public void put(int key, int value) {
        Entry entry = findByKey(key);
        if (entry == null) {
            if (size == capacity) {
                list.removeLast();
                size--;
            }
            list.addFirst(new Entry(key, value));
            size++;
        } else {
            list.remove(entry);
            list.addFirst(entry);
            entry.value = value;
        }
    }

    private Entry findByKey(int key) {
        for (Entry entry : list) {
            if (entry.key == key) {
                return entry;
            }
        }
        return null;
    }
}
