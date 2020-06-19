package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        MaxQueue obj = new MaxQueue();

        int param_1 = obj.max_value();
        System.out.println(param_1);

        obj.push_back(3);
        obj.push_back(6);
        obj.push_back(1);
        obj.push_back(15);
        obj.push_back(53);
        obj.push_back(38);

        int param_2 = obj.max_value();
        System.out.println(param_2);

        int param_3 = obj.pop_front();
        System.out.println(param_3);
    }
}
