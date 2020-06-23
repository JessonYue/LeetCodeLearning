package com.test.ktapplication;


import android.util.Log;

public class Main {

    void main() {
        int nums[] = {12, 345, 2, 6, 7896};
        int result = findNumbers(nums);
        Log.e("result is", result + "");
    }

    public int findNumbers(int[] nums) {
        int count = 0;
        for (int num : nums) {
            if (String.valueOf(num).length() % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}


