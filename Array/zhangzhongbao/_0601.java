package com.company;

/**
 * 两数之和 II - 输入有序数组
 * 解题思路：数组是排序的，就按照两边同时向中间前进的方式循环迭代
 */
public class _0601 {

    public static void main(String[] args) {
//        int []numbers = {2, 7, 11, 15};
        int[] numbers = {2, 4, 6, 8, 10, 13, 19, 21};
        int result[] = twoSum(numbers, 14);
        System.out.println(result[0] + " -" + result[1]);
    }

    public static int[] twoSum(int[] numbers, int target) {
        int index[] = {0, 0};
        int a = 0;
        int b = numbers.length - 1;
        for (a = 0; a <= b; ) {
            if (numbers[a] + numbers[b] > target) {
                b--;
            } else if (numbers[a] + numbers[b] < target) {
                a++;
            } else {//可能找到了
                break;
            }
            System.out.println(a + " " + b);
        }
//        System.out.println(a+" "+b);
        if (a < b) {//a和b不能相等
            index[0] = a + 1;
            index[1] = b + 1;
        }
        return index;
    }
}
