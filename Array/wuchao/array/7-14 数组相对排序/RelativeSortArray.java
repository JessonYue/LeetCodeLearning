package com.slow.lib.practice.array;

/**
 * 给你两个数组，arr1 和 arr2，
 *
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
 *
 * 思路是建立一个计数的数组，下标是arr1的元素值，值是出现次数，因为题目里面规定了元素的大小不会超过1000，所以能这样处理，否则如果太大性能就不行了。
 * 通过这个计数数组遍历arr2，因为arr2元素都出现在arr1中，按照arr2的元素顺序，再加上计数数组的个数，向新数组插入元素。直到遍历完arr2，这样arr1中所有arr2的元素就都排序好了。
 * 再来排序arr1中没有在arr2中出现的元素，这次遍历计数数组，因为arr2中出现的元素计数已经减少到0了，所以只取计数值大于0的下标，这个下标就是在arr1中没有出现在arr2里的数
 * 而且巧合的是，因为是从头到尾遍历，所以下标就是升序排列，所以取出来的数直接插入新数组，不用再排序了。
 * @Author wuchao
 * @Date 2020/7/14-11:04 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class RelativeSortArray {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] countArray = new int[1001];
        int[] newArray = new int[arr1.length];
        for(int item:arr1){
            countArray[item]++;
        }
        int index = 0;
        for(int item:arr2){
            while(countArray[item]>0){
                newArray[index++] = item;
                countArray[item]--;
            }
        }
        //遍历计数数组取计数大于0的下标，则是arr1中没有在arr2里出现的元素，因为是从小到大遍历，所以就是升序的，感觉这里很巧妙。
        for(int i = 0;i<countArray.length;i++){
            while(countArray[i]>0){
                newArray[index++] = i;
                countArray[i]--;
            }
        }
        return newArray;
    }
}
