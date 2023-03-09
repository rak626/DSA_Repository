// Best Time to Buy and Sell Stock II

// memoization
#include <bits/stdc++.h>
long f(int i, int buy, long *values, int n, vector<vector<long>> &dp) {
  if (i == n)
    return 0;
  if (dp[i][buy] != -1)
    return dp[i][buy];
  long profit = 0;
  if (buy) {
    profit = max(-values[i] + f(i + 1, 0, values, n, dp),
                 f(i + 1, 1, values, n, dp));
  } else {
    profit =
        max(values[i] + f(i + 1, 1, values, n, dp), f(i + 1, 0, values, n, dp));
  }
  return dp[i][buy] = profit;
}

long getMaximumProfit(long *values, int n) {
  vector<vector<long>> dp(n, vector<long>(2, -1));
  return f(0, 1, values, n, dp);
}

// tabulation
#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n) {
  vector<vector<long>> dp(n + 1, vector<long>(2, -1));
  dp[n][0] = dp[n][1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int buy = 0; buy <= 1; buy++) {
      long profit = 0;
      if (buy) {
        profit = max(-values[i] + dp[i + 1][0], dp[i + 1][1]);
      } else {
        profit = max(values[i] + dp[i + 1][1], dp[i + 1][0]);
      }
      dp[i][buy] = profit;
    }
  }
  return dp[0][1];
}

// space optimization

#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n) {
  vector<long> prev(2, 0), cur(2, 0);
  prev[0] = prev[1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int buy = 0; buy <= 1; buy++) {
      long profit = 0;
      if (buy) {
        profit = max(-values[i] + prev[0], prev[1]);
      } else {
        profit = max(values[i] + prev[1], prev[0]);
      }
      cur[buy] = profit;
    }
    prev = cur;
  }
  return prev[1];
}