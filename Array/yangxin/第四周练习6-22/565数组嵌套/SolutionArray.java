package com.example.admin.myapplication.array;

/**
 * create by yx
 * on 2020/6/22
 */
public class SolutionArray {
    /**
     * 565. 数组嵌套
     * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
     * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，
     * 不断添加直到S出现重复的元素。
     */
    public int arrayNesting(int[] nums) {
        int length = nums.length;
        if (length == 0) {
            return 0;
        }

        byte[] bitMap = new byte[length];

        int target = 0;
        for (int i = 0; i < length; i++) {
            //重复出现意味着产生环，重点理解这点
            if (bitMap[nums[i]] == 0) {
                int start = nums[i], count = 0;
                do {
                    bitMap[nums[start]] = 1;
                    start = nums[start];
                    count++;
                } while (start != nums[i]);//相等意味着产生环
                target = Math.max(target, count);
            }
        }
        return target;
    }
}
