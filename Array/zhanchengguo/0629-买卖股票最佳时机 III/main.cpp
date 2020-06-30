#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

int maxProfit(vector<int> &prices);

int main() {
    int a[] = {3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> v(a, a + 8);
    int result = maxProfit(v);
    printf("params2 is %d", result);
    return 0;
}

/**
 * 思路：穷举每天的不同状态下的利润
 * 三维数组分别表示：第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态
 * @param prices
 * @return
 */
int maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size();
    int max_k = 2;
    int dp[n][max_k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= max_k; ++k) {
            if (i == 0) {
                dp[0][k][0] = 0;
                dp[0][k][1] = -prices[0];
                continue;
            }
            //今天我没有持有股票，有两种可能：
            //要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
            //要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            //今天我持有着股票，有两种可能：
            //要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
            //要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][max_k][0];
}




