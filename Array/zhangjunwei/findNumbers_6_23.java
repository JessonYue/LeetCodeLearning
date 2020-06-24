package com.lanfairy.md.queue;

import java.util.ArrayList;

public class findNumbers_6_23 {
    public int findNumbers(int[] nums) {

        int count = 0;
        for (int num : nums) {
            if (Integer.toString(num).length() % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}
