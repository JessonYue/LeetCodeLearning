package com.lanfairy.md;

import android.util.ArraySet;
import android.util.SparseIntArray;

import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class Solution {
    public int arrayNesting1(int[] nums) {
        int size = nums.length;
        Set<Integer> set = new TreeSet<>();
        int sMaxNum = 0;//最大的集合有的元素个数
        for (int i = 0; i < size; i++) {
            int j = i;

            while (!set.contains(nums[j])) {
                set.add(nums[j]);
                j = nums[j];
            }
            if (sMaxNum < set.size())
                sMaxNum = set.size();
            set.clear();
        }

        return sMaxNum;

    }

    public int arrayNesting(int[] nums) {
        int size = nums.length;
        int sMaxNum = 0;//最大的集合有的元素个数
        boolean[] visted = new boolean[size];
        for (int i = 0; i < size; i++) {
            if (!visted[i]) {
                int start = nums[i];
                int count = 0;
                do {
                    visted[start] = true;
                    start = nums[start];
                    count++;
                }while (start!=nums[i]);

                sMaxNum = Math.max(sMaxNum, count);
            }
        }

        return sMaxNum;

    }

    public static void main(String[] args) {
        int[] num = new int[]{5, 4, 0, 3, 1, 6, 2};

        int res = new Solution().arrayNesting(num);
        System.out.println(res);
    }

}
