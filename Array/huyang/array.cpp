//两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> obj;
        vector<int> asn;
        for(int i=0;i<nums.size();i++){
            obj.push_back(target-nums[i]);
        }
        for(int i=0;i<nums.size();i++ ){
            for(int j=0;j<nums.size();j++ ){
                if(obj[i]==nums[j]&&i!=j){
                    asn.push_back(i);
                    asn.push_back(j);
                    return asn;
                }
            }
        }
         return asn;
    }
};




//爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        if(n ==0 ){
            return 0;
        }

        if(n == 1){
            return 1;
        }

        if( n == 2 ){
            return 2;
        }

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


//第三道strstr()
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.length() < needle.length()){
            return -1;
        }

        if(needle.length() == 0){
            return 0;
        }

        for(int i = 0 ; i<= haystack.length() - needle.length(); i ++ ){
            int j = 0;
            for( j = 0 ; j < needle.length(); j ++ ){
                if(haystack[i + j ] != needle[j]){
                    break;
                }
               
            }
             if(j == needle.length()){
                   return i; 
                }
        }
        return -1;
    }
};


