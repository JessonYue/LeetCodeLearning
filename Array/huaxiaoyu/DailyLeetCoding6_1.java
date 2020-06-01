package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding6_1 {
    //2020.06.1
    //1 两数之和 II - 输入有序数组
    //给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
    //函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

    //说明:
    //返回的下标值（index1 和 index2）不是从零开始的。
    //你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    //示例:
    //输入: numbers = [2, 7, 11, 15], target = 9
    //输出: [1,2]
    //解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

    // 自我思考实现
    // 1. 找到数组中小于target的数的下标
    // 2. 定义两个变量记录记录最大和最小
    // 3. 两数相加大于target, 最大减一, 小于则最小加一
    @Test
    public void test() {
        int[] nums = new int[]{3, 2, 4};
        int[] result = getSumIndex(nums, 6);
        System.out.println("index1: " + result[0] + "; index2: " + result[1]);
    }

    public int[] getSumIndex(int[] numbers, int target) {
        int[] result = new int[]{-1, -1};
        if (null == numbers || numbers.length <= 1) {
            return result;
        }
        int start = 0, end = numbers.length - 1;
        while (start != end) {
            if (numbers[start] + numbers[end] > target) {
                end--;
            } else if (numbers[start] + numbers[end] < target) {
                start++;
            } else {
                result[0] = ++start;
                result[1] = ++end;
                return result;
            }
        }
        return result;
    }
}
