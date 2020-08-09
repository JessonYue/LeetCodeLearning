#include <stdbool.h>

/**
 *
思路就是先清0,然后M左移i位与N
注意点:1.移位的时候1必须是unsigned int !
2.熟练掌握清0 和置1 的方法
 */
int insertBits(int N, int M, int i, int j) {
    for (int start = i; start <= j; start++)
        N &= ~((unsigned int) 1 << start);
    N |= (M << i);
    return N;
}

//给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
bool hasAlternatingBits(int n) {
    n = (n ^ (n >> 1));
    return (n & ((long) n + 1)) == 0;
}
