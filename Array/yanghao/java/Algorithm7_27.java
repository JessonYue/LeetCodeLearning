package com.example.servlet;


import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

public class Algorithm7_27 {
	
	public static class LRUCache{
		
		Map<Integer, Integer> map;
		int max;
		Map<Integer,Integer> list = new HashMap();
		TreeSet<Integer> set = new TreeSet<>();
		public LRUCache(int capacity) {
	        map = new HashMap<Integer, Integer>();
	        max = capacity;
	    }
	    
	    public int get(int key) {
	    	for (int a : list.keySet()) {
				if (a == key) {
					list.put(key, list.get(key)+1);
				}
			}
	    	
	    	System.out.println(list);
	    	return map.get(key);
	    }
	    
	    public void put(int key, int value) {
	    	if (map.size() < max) {
				map.put(key, value);
				list.put(key, 0);
			}else {
				for (Integer a : list.keySet()) {
					set.add(list.get(a));
				}
				
			}
	    }
	}
	
	public static void main(String[] args) {
		Algorithm7_27.LRUCache lCache = new LRUCache(2);
		lCache.put(1, 1);
		lCache.put(2, 2);
		lCache.get(2);
	}
}
