class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] sum = new int [2];
        for(int i = 0 ; i < nums.length ; i ++ ){

            int res = target - nums[i];


            if(map.containsKey(res)){
              int index =   map.get(res);
              sum[0] = index;
              sum[1] = i;
              return sum;
            }

            map.put(nums[i], i );


        }
        return sum;

    }
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
dp[1] = 1;
dp[2] = 2;
for(int i = 3;i<=n;i++)
{
dp[i] = dp[i-1] +dp[i-2] ;
}
return dp[n] ;
}
};