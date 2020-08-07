package com.slow.lib.practice.others;

import java.util.HashMap;

/**
 * @Author wuchao
 * @Date 2020/8/7-9:40 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Object> map = new HashMap();
        final Object dummy = new Object();
        for(int item:nums){
            if(map.put(item,dummy)!=null) return true;
        }
        return false;
    }
}
