class Solution {
    public int climbStairs(int n) {
        if(n <= 0) return 0;
        // return dynamic(n);
        return dynamicOpt(n);
    }

    // 动态规划
    int dynamic(int n) {
        int[] result = new int[n+1];
        result[0] = 0;
        result[1] = 1;
        if(n >= 2) {
            result[2] = 2;
            for(int i = 3; i < n + 1; i++) {
                result[i] = result[i - 1] + result[i - 2];
            }
        }
        return result[n];
    }

    // 动态规划优化空间复杂度为O(1)
    int dynamicOpt(int n) {
        int first = 1;
        int second = 2;
        if(n >= 2) {
            int temp = 0;
            for(int i = 3; i < n + 1; i++) {
                temp = first + second;
                first = second;
                second = temp;
            }
            return second;
        }
        return first;
    }

}