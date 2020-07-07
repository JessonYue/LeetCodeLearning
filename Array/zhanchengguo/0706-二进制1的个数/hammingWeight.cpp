#include <iostream>

int hammingWeight(uint32_t n);

int main() {
    int result = hammingWeight(00000000000000000000000000001011);
    printf("result is %d", result);

}

/**
 * 思路；按位与运算，一个数与它小1的数按位与运算，可以消除n的最低位的1
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}