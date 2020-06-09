
//斐波那契数列的公式

#include <math.h>
int climbStairs(int n){
    double sqrt_5 = sqrt(5);
    double fib_n = pow((1 + sqrt_5) / 2, n + 1) - pow((1 - sqrt_5) / 2,n + 1);
    return (int)(fib_n / sqrt_5);
}