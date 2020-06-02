package com.example.testapplication;

import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        int[] positions = twoSum(new int[]{1, 5, 7, 23, 8, 3}, 4);
        int[] positions1 = twoSum1(new int[]{1, 5, 7, 23, 8, 3}, 15);
        System.out.println(positions[0]);
        System.out.println(positions[1]);
        System.out.println(positions1[0]);
        System.out.println(positions1[1]);
    }

    public static int[] twoSum(int[] sums, int target) {
        for (int i = 0; i < sums.length - 1; i++) {
            for (int j = 1 + i; j < sums.length; j++) {
                if (sums[i] == target - sums[j]) {
                    return new int[]{i, j};
                }
            }
        }
        throw new IllegalArgumentException("参数不符合规则");
    }
    public static int[] twoSum1(int[] sums, int target){
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < sums.length; i++) {
            map.put(sums[i],i);
        }
        for (int i = 0; i < sums.length; i++) {
            int sum=target-sums[i];
            Integer key = map.get(sum);
            if (map.containsKey(sum)&& key !=i) {
                return new int[]{i, key};
            }
        }
        throw new IllegalArgumentException("参数不符合规则");
    }
}
