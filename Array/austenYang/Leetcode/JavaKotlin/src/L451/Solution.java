package L451;

import java.util.*;

public class Solution {
    //"tree"

    /**
     * 1.字符用 Map<char,int> 来保存字符出现的评率
     * 2.将 Map 接口 转出 Entry<char,int> 的 List 集合，
     * 因为 List 集合方便使用 Comparable 自定义比较器
     * 3.自定义排序后遍历 List<Entry<char,int>> 在遍历中，int > 1 在循环 拼接多个
     *
     * @param s
     * @return
     */
    public static String frequencySort1(String s) {
        char[] chars = s.toCharArray();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char aChar : chars) {
            Integer count = map.get(aChar);
            if (count == null) {
                map.put(aChar, 1);
            } else {
                map.put(aChar, ++count);
            }
        }


        ArrayList<Map.Entry<Character, Integer>> mapEntryList = new ArrayList<>(map.entrySet());
        Collections.sort(mapEntryList, (o1, o2) -> o2.getValue() - o1.getValue());

        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Character, Integer> maps : mapEntryList) {
            Character character = maps.getKey();
            Integer value = maps.getValue();
            for (int i = 0; i < value; i++) {
                sb.append(character);
            }
        }
        return sb.toString();
    }


    public static void main(String[] args) {
        System.out.println(frequencySort1("tree"));

    }
}
