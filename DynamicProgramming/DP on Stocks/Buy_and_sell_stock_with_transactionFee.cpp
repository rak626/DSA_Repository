// Best Time to Buy and Sell Stock with Transaction Fee
#include <bits/stdc++.h>
int f(int i, int buy, int fee, int n, vector<int> &prices,
      vector<vector<int>> &dp) {
    if (i == n) return 0;
    if (dp[i][buy] != -1) return dp[i][buy];
    if (buy) {
        return dp[i][buy] = max(-prices[i] + f(i + 1, 0, fee, n, prices, dp),
                                f(i + 1, 1, fee, n, prices, dp));
    } else {
        return dp[i][buy] =
                   max(prices[i] - fee + f(i + 1, 1, fee, n, prices, dp),
                       f(i + 1, 0, fee, n, prices, dp));
    }
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, fee, n, prices, dp);
}

// tabulation

#include <bits/stdc++.h>
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }
        }
    }
    return dp[0][1];
}