package com.slow.lib.practice.array;

/**
 * 这道题的关键在于S数组的元素最终会形成一个循环，每个元素的值是下一个元素在原始数组nums中的下标。
 * 关键点在于原始数组的nums元素是不重复的，因此不可能存在从循环外部的元素跳到循环里的元素的情况，因为如果这种情况发生，原始数组的元素就重复了。
 * 因此我们可以标记原始数组已经遍历的元素，之后遇到已经遍历的元素就跳过。这里没有要求保留原始数组，那么可以直接在原始数组上标记，遍历的元素标记为负数（这里取-1），因为nums的元素都是非负的
 * @Author wuchao
 * @Date 2020/6/22-10:29 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ArrayNestingSolution {
    public int arrayNesting(int[] nums) {
        int max = 0;
        for(int i=0;i<nums.length;i++){
            int count = 0;
            int sItemIndex = i;
            while(nums[sItemIndex]!=-1){
                count++;
                int temp = sItemIndex;
                sItemIndex = nums[sItemIndex];
                nums[temp] = -1;
            }
            max = Math.max(count,max);
        }
        return max;
    }
}
