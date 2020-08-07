package day61_0731_leetcode349;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class day61_leetcode349 {

    public static void main(String[] args) {
        int[] l = {9,6,5,7};
        Arrays.sort(l);
        for (int i = 0; i < l.length; i++) {
            System.out.println(l[i]);
        }
    }


    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums1.length; i++) {
            int target = nums1[i];
        }
        return null;
    }

    //public static int binarySearch(int[] array, int fromIndex, int toIndex, int key){
    public static int binarySearch(int[] array, int key){
        int low = 0; //低位指针
        int high = array.length -1;//高位指针,注意左闭右开
        while (low <= high){
            int mid = (low+high)/2;  //中间指针
            int midValue = array[mid];
            if(key > midValue){
                low = mid+1;   //小于目标值,移动低位指针
            }else if(key < midValue){
                high = mid-1;  //大于目标值,移动高位指针
            }else{
                return mid;
            }
        }
        return -(low+1);   //未找到,直接返回出去
    }

}
