package day43_0713;

import java.util.HashMap;

public class day43_leetcode381 {


    public int firstUniqChar(String s) {
        HashMap<Character,Integer> hashMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            hashMap.put(c,hashMap.getOrDefault(c,0)+1);
        }

        for (int i = 0; i < s.length(); i++) {
            if(hashMap.get(s.charAt(i))==1)
                return i;
        }
        return -1;
    }
}
