
//两数之和
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

//爬楼梯
class Solution {
    public int climbStairs(int n) {
        if(n ==0 ){
            return 0;
        }

        if(n == 1){
            return 1;
        }

        if( n == 2 ){
            return 2;
        }

        int[] dp = new int[n+1];
        dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
        for(int i = 3;i<=n;i++)
        {
            dp[i] = dp[i-1] +dp[i-2] ;
        }
		return dp[n] ;
	    
    }
}