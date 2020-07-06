package jdbc.mvc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.LinkedList;
import java.util.Queue;

import jdbc.mvp.Constrct;

public class Algorithm6_18 {

	private Queue<Integer> queue = new LinkedList<Integer>();
	LinkedList<Integer> max = new LinkedList<>();
	public Algorithm6_18() {

    }
    
    public int max_value() {
    	return max.size() <= 0 ? -1 : max.getFirst();
    }
    
    public void push_back(int value) {
    	queue.add(value);
    	while (max.size() != 0 &&max.getLast() < value) {
			max.removeLast();
		}
    	max.add(value);
    }
    
    public int pop_front() {
    	if (max.size() != 0 && queue.peek().equals(max.getFirst())) {
			max.removeFirst();
		}
    	return queue.size() == 0 ? -1 : queue.poll();
    }
}
