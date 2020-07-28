package com.slow.lib.practice.array;

import java.util.HashMap;
import java.util.Map;

/**
 * @Author wuchao
 * @Date 2020/7/28-10:06 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindArrayIntersection {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer,Integer> maps = new HashMap();
        Map<Integer,Integer> maps2 = new HashMap();
        for(int item:nums1){
            maps.put(item,1);
        }
        for(int item:nums2){
            if(maps.containsKey(item)){
                maps2.put(item,1);
            }
        }
        int[] intersection = new int[maps2.size()];
        int i=0;
        for(int key:maps2.keySet()){
            intersection[i++] = key;
        }
        return intersection;
    }
}
