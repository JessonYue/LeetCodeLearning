package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here

        MyQueue obj = new MyQueue();
        //obj.push(3);
        obj.push(5);
        obj.push(13);

        int param_2 = obj.pop();
        System.out.println(param_2);

        int param_3 = obj.peek();
        System.out.println(param_3);

        boolean param_4 = obj.empty();
        System.out.println(param_4);

        int param_5 = obj.pop();
        System.out.println(param_5);

        boolean param_6 = obj.empty();
        System.out.println(param_6);
    }
}
