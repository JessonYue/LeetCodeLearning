#include <stdio.h>
#include <stdlib.h>

int maxProfit(int prices[], int count);

int minValue(int minValue, int price);

int maxValue(int maxValue, int price);

int maxProfit(int prices[], int count) {

    if (count < 2) {
        return 0;
    }
    int minPrice1 = INT_MAX;
    int maxProfit1 = 0;
    int maxProfitAfterBuy = INT_MIN;
    int maxProfit2 = 0;
    for (int i = 0; i < count; ++i) {
        minPrice1 =minValue(minPrice1,prices[i]);//第一次最小购买价格
        maxProfit1 = maxValue(maxProfit1,prices[i]);//第一次卖出的最大利润
        maxProfitAfterBuy = maxValue(maxProfitAfterBuy,maxProfit1-prices[i]);//第二次购买后的剩余净利润
        maxProfit2 = maxValue(maxProfit2,prices[i]+maxProfitAfterBuy);//第二次卖出后，总共获得的最大利润(第3步的净利润+第4步卖出的股票价)
    }
    return maxProfit2;
}

int minValue(int minValue, int price) {
    int value = 0;
    value = minValue < price ? minValue : price;
    return value;
}

int maxValue(int maxValue, int price) {
    int value = 0;
    value = maxValue > price ? maxValue : price;
    return value;
}