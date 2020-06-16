package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        MyStack obj = new MyStack();
        obj.push(6);
        obj.push(9);
        obj.push(14);
        obj.push(3);
        obj.push(-25);
        printStack(obj);
//        int param_2 = obj.pop();
//        System.out.println(param_2);
//        int param_3 = obj.top();
//        System.out.println(param_3);
//        boolean param_4 = obj.empty();
    }

    private static void printStack(MyStack obj){
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append('[');
        while (!obj.empty()){
            stringBuilder.append(obj.pop());
            if(obj.size() > 0){
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append(']');
        System.out.println(stringBuilder.toString());
    }
}
