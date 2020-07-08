//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a)>(b) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
    if(prices == NULL || pricesSize == 0){
        return 0;
    }
    int min = prices[0];
    int max = prices[pricesSize - 1];

    int maxPro1 = 0;
    int maxPro2 = 0;

    int* profit1 = (int*)malloc(pricesSize*sizeof(int));
    int* profit2 = (int*)malloc(pricesSize*sizeof(int));

    for(int i = 0; i < pricesSize; i++){
        if(prices[i] <= min){
            min = prices[i];
        }else{
            maxPro1 = MAX(maxPro1, prices[i] - min);
        }
        profit1[i] = maxPro1;

        if(prices[pricesSize - 1 - i] >= max){
            max = prices[pricesSize - 1 - i];
        }else{
            maxPro2 = MAX(maxPro2, max - prices[pricesSize - 1 -i]);
        }
        profit2[pricesSize - 1 - i] = maxPro2;
    }
    int res = 0;
    for(int i = 0; i < pricesSize; i++){
        res = MAX(res, profit1[i] + profit2[i]);
    }
    free(profit1);
    free(profit2);
    return res;
}
int main() {

    return 0;
}