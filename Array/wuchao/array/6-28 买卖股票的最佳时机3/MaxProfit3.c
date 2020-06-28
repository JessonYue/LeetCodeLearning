#include <limits.h>
//
// Created by 吴超 on 2020/6/28.
//
int intMax(int a,int b);
int intMin(int a,int b);
int maxProfit(int* prices, int pricesSize){
    int firstBuyMinPrice = INT_MAX;
    int firstSaleMaxProfit = 0;
    int secondBuyMaxLeftProfit = INT_MIN;
    int secondSaleMaxProfit = 0;
    for(int i=0;i<pricesSize;i++){
        firstBuyMinPrice = intMin(prices[i],firstBuyMinPrice);
        firstSaleMaxProfit = intMax(firstSaleMaxProfit,prices[i]-firstBuyMinPrice);
        secondBuyMaxLeftProfit = intMax(secondBuyMaxLeftProfit,firstSaleMaxProfit-prices[i]);
        secondSaleMaxProfit = intMax(secondSaleMaxProfit,secondBuyMaxLeftProfit+prices[i]);
    }
    return secondSaleMaxProfit;
}

int intMin(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int intMax(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}


