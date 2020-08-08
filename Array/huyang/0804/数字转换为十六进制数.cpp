
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。


class Solution {
public:
    string toHex(int num) {
        string res;
        int low=0,high=0;
        if(num==0){
            return "0";
        }
        char map[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num&&res.size()<8){
            res=map[(num&0xf)]+res;
            num=num>>4;
        }
        return res;
    }
};