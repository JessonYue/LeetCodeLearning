class Solution {
    public int strStr(String haystack, String needle) {
        if(haystack == null || needle == null  
            || haystack.length() < needle.length()) {
                return -1;
        }
        if(haystack.length() == 0 || needle.length() == 0){
            return 0;
        }

        //return baoStr(haystack, needle);
        return KMPStr(haystack, needle);
    }

    // KMP字符串匹配法
    int KMPStr(String haystack, String needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        // state 为状态二维数组，state[1]['a'的Ascall码对应的值]，表示当前状态为1，匹配'a'之后，状态的值
        int[][] state = new int[needleLen][128];
        // 第一次匹配的时候，只有相同的值，才为1
        state[0][needle.charAt(0)] = 1;
        // 影子的状态值
        int X = 0;
        // 初始化状态数组
        for(int i = 1; i < needleLen; i++) {
            for(int j = 0; j < 128; j++) {
                // 都转化为X的状态遇到这些字符后的状态
                state[i][j] = state[X][j];
            }
            // 只有匹配上了，状态值才会递增
            state[i][needle.charAt(i)] = i + 1;
            // 更新X的状态，这里i从1开始，相当于找到下一个与前面重复的子串，这就是所谓的影子状态
            X = state[X][needle.charAt(i)];
        }

        int l = 0;
        // 查找
        for(int k = 0; k < haystackLen; k++) {
            l = state[l][haystack.charAt(k)];
            if(l == needleLen) return k - l + 1;
        }
        return -1;
    }

    // 暴力求解
    int baoStr(String haystack, String needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        for(int i = 0; i < haystackLen && haystackLen - i >= needleLen; i++) {
            int j = 0;
            for(; j < needleLen; j++) {
                if(haystack.charAt(i+j) != needle.charAt(j)) {
                    break;
                }
            }
            if(j == needleLen && j != 0) {
                return i;
            }
        }
        return -1;
    }

}