class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n & 1;

        while(n){
            n = n>>1;
            int bit1 =n&1;

            if(bit== bit1){
                return false;
            }
            bit = n&1;
        }
        return true;
    }
};