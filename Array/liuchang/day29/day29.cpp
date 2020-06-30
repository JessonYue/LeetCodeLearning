//
// Created by 刘畅 on 2020/6/29.
//

#include "day29.h"
#include "iostream"

int maxProfit(int *prices, int pricesSize);

#define     MAX(a, b)       ((a) > (b) ? (a) : (b))

int maxProfit(int *prices, int pricesSize) {
    int i = 0;
    int dp1 = 0;
    int dp2 = -0xFFFF;
    int dp3 = 0;
    int dp4 = -0xFFFF;

    for (i = 0; i < pricesSize; i++) {
        dp3 = MAX(dp3, dp4 + prices[i]);
        dp4 = MAX(dp4, dp1 - prices[i]);
        dp1 = MAX(dp1, dp2 + prices[i]);
        dp2 = MAX(dp2, 0 - prices[i]);
    }

    return dp3;
}

int main() {
    int datas[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("%d\n", maxProfit(datas, 8));
    return 0;
}
