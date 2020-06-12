//
// Created by mac on 2020/6/4.
//

#include "topic_3_strstr.h"
#include <vector>
using namespace std;

int Algorithm::climbStairs(int target) {
    vector<int> dp(target + 2, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= target; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[target];
}