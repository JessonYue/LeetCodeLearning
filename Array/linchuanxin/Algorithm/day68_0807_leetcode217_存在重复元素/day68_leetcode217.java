package day68_0807_leetcode217;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class day68_leetcode217 {
    public static void main(String[] args) {
        int[] nums = {1,1,1,3,3,4,3,2,4,2};
//        int[] nums = {1,2,3,4};
        //int[] nums = {1,2,3,1};
        System.out.println(day68_leetcode217.containsDuplicate(nums));
        System.out.println(day68_leetcode217.containsDuplicate2(nums));
    }

    public static boolean containsDuplicate(int[] nums) {
        if (nums.length==0)
            return false;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if(!set.isEmpty())
                if (set.contains(nums[i]))
                    return true;
            set.add(nums[i]);
        }
        return false;
    }

    public static boolean containsDuplicate2(int[] nums) {
        if (nums.length==0)
            return false;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if(i+1 < nums.length){
                if(nums[i] == nums[i+1])
                    return true;
            }
        }
        return false;
    }
}
