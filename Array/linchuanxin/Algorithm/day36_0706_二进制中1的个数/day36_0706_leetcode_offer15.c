//
// Created by LCX on 2020/7/6.
//

typedef int uint32_t;
int hammingWeight(uint32_t n) {
    int res = 0;
    while (n!=0)
    {
        res += n & 1;
        n = n >> 1;
    }
    return res;
}