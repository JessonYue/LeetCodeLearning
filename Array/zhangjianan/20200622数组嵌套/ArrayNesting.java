package com.test;

public class ArrayNesting {
    public static void main(String[] args) {
        int[] haystack = new int[]{5, 4, 0, 3, 1, 6, 2};
        System.out.println(arrayNesting(haystack));
    }

    /**
     *首先我们来看示例中结果{A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}，
     * 不难发现这是一个环5->6->2->0->5，这个在这个环中的元素作为入口得到的结果都是4，
     * 比如我们现在是以5为入口，当我们以6作为入口时得到的结果是6->2->0->5->6，长度也是4。
     * 这就说明如果进行暴搜将会存在大量的重复计算。我们计算每一个环的长度即可。
     */
    public static int arrayNesting(int[] nums) {
        int max=0;
        for (int i = 0; i < nums.length; i++) {
            int index=i,tempMax=0;
            while (nums[index]!=-1){
                tempMax++;
                int temp = nums[index];
                nums[index]=-1;
                index=temp;
            }
            max=max>tempMax?max:tempMax;
        }
        return max;
    }
}
