class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count =0 ;

        
        for(int i = 0 ; i < nums.size();i++){
            int n = nums[i], even=0;
            while(n>0){
                n/=10;
                even++;
            }
            if(even %2 == 0){
                count++;
            }
        }
        return count;
    }
};