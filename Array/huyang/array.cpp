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



//第四道  合并排序的数组
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(n == 0){
           return;
        }

        if(m == 0){
            A = B;
        }

        int pa = m-1;
        int pb = n-1;
        int p = m+n-1;
        while(pa >= 0  &&  pb >= 0  ){
            if(B[pb] > A[pa]){
               A[p] = B[pb];
               pb--;
            }else{
               A[p] = A[pa];
               pa--;
            }
            p --;
        }

        while(pa >= 0){
            A[p] = A[pa];
            pa--;
            p --;
        }

        while(pb >= 0){
            A[p] = B[pb];
            pb--;
            p --;
        }


    }
};
