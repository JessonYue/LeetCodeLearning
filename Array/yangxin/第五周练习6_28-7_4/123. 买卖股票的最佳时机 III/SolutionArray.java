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

    /**
     * 1295. 统计位数为偶数的数字
     * 给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
     */
    public int findNumbers(int[] nums) {
        int count = nums.length;
        if (count == 0) {
            return 0;
        }

        int result = 0;
        int tmp = 0, bit = 0;
        for (int i = 0; i < count; i++) {
//            if (String.valueOf(nums[i]).length() % 2 == 0) {
//                result++;
//            }
            tmp = nums[i];
            bit = 0;
            while (tmp != 0) {
                tmp = tmp / 10;
                bit++;
            }
            if (bit % 2 == 0) {
                result++;
            }
        }

        return result;
    }


    /**
     * 1343. 大小为 K 且平均值大于等于阈值的子数组数目
     * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
     * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
     */
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        if (arr.length == 0) {
            return 0;
        }
        int sunTarget = k * threshold;
        int sum = 0;
        int result = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int adder = sum - sunTarget;
        if (adder >= 0) {
            result++;
        }
        for (int i = 0, pos = k, count = arr.length - k; i < count; i++, pos++) {
            adder += arr[pos] - arr[i];
            if (adder >= 0) {
                result++;
            }
        }

        return result;
    }


    /**
     * 123. 买卖股票的最佳时机 III
     * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
     * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
     * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
     *
     * 参考网上解题思路，不是非常理解，需要多次练习
     */
    public int maxProfit(int[] prices) {
        if (prices.length < 2) {
            return 0;
        }

        int minPrice1 = Integer.MAX_VALUE;
        int maxProfit1 = 0;
        int maxProfitAfterBuy = Integer.MIN_VALUE;
        int maxProfit2 = 0;
        for(int price : prices) {
            // 1.第一次最小购买价格
            minPrice1  = Math.min(minPrice1,  price);

            // 2.第一次卖出的最大利润
            maxProfit1 = Math.max(maxProfit1, price - minPrice1);

            // 3.第二次购买后的剩余净利润
            maxProfitAfterBuy  = Math.max(maxProfitAfterBuy,  maxProfit1 - price );

            // 4.第二次卖出后，总共获得的最大利润（第3步的净利润 + 第4步卖出的股票钱）
            maxProfit2 = Math.max(maxProfit2, price + maxProfitAfterBuy);
        }
        return maxProfit2;
    }
}
