#include <stdio.h>

#define     MAX(a, b)       ((a) > (b) ? (a) : (b))
#define     MIN(a, b)       ((a) < (b) ? (a) : (b))

int maxProfit(int *prices, int pricesSize) {
    int i = 0;
    int minPrice1 = 0xFFFF;//1.第一次最小买入价格
    int maxProfit1 = 0;//2.第一次卖出最大利润
    int maxProfitAfterBuy = -0xFFFF;//3.第二次购买后的剩余净利润
    int maxProfit2 = 0;// // 4.第二次卖出后，总共获得的最大利润（第3步的净利润 + 第4步卖出的股票钱）

    for (i = 0; i < pricesSize; i++) {
        minPrice1 =MIN(minPrice1,prices[i]);
        maxProfit1=MAX(maxProfit1,prices[i]-minPrice1);
        maxProfitAfterBuy=MAX(maxProfitAfterBuy,maxProfit1-prices[i]);
        maxProfit2=MAX(maxProfit2,prices[i]+maxProfitAfterBuy);
    }

    return maxProfit2;
}

int main() {

    int arr[8] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf(maxProfit(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}
