class Solution {
    public int firstUniqChar(String s) {
int[] count = new int[26];//计数
        char[] array = s.toCharArray();
        for (char c : array) 
            count[c - 'a']++;
        
        
        for (int i = 0; i < s.length(); i++) 
            if (count[array[i] - 'a'] == 1)
                return i;

       
        return -1;
    }
}
