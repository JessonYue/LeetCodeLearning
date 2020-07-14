class Solution {
public:
    string toHex(int nums) {
        unsigned int num=nums;
        string arr ="0123456789abcdef";
        if(num==0) return "0";
        string res;
       while (num){
           int tmp=num&15;
           res.push_back(arr[tmp]);
           num=num>>4;
       }
       
        reverse(res.begin(),res.end());
        return res;

    }
};