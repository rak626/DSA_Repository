// best time to buy and sell stock III

// memoization
#include <bits/stdc++.h>
int f(int day, int buy, int cap, int n, vector<int> &prices,
      vector<vector<vector<int>>> &dp) {
    if (cap == 0) return 0;
    if (day == n) return 0;
    if (dp[day][buy][cap] != -1) return dp[day][buy][cap];
    if (buy) {
        return dp[day][buy][cap] =
                   max(-prices[day] + f(day + 1, 0, cap, n, prices, dp),
                       f(day + 1, 1, cap, n, prices, dp));
    } else {
        return dp[day][buy][cap] =
                   max(prices[day] + f(day + 1, 1, cap - 1, n, prices, dp),
                       f(day + 1, 0, cap, n, prices, dp));
    }
}
int maxProfit(vector<int> &prices, int n) {
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, n, prices, dp);
}

// tabulation
#include <bits/stdc++.h>
int maxProfit(vector<int> &prices, int n) {
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));
    for (int day = n - 1; day >= 0; day--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy) {
                    dp[day][buy][cap] = max(-prices[day] + dp[day + 1][0][cap],
                                            dp[day + 1][1][cap]);
                } else {
                    dp[day][buy][cap] =
                        max(prices[day] + dp[day + 1][1][cap - 1],
                            dp[day + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// space optimization using four transaction technique

// memoization
#include <bits/stdc++.h>
int f(int day, int trans, int n, vector<int> &prices, vector<vector<int>> &dp) {
    if (day == n or trans == 4) return 0;

    if (dp[day][trans] != -1) return dp[day][trans];
    // sell
    if (trans & 1) {
        return dp[day][trans] =
                   max(prices[day] + f(day + 1, trans + 1, n, prices, dp),
                       f(day + 1, trans, n, prices, dp));
    } else {  // buy
        return dp[day][trans] =
                   max(-prices[day] + f(day + 1, trans + 1, n, prices, dp),
                       f(day + 1, trans, n, prices, dp));
    }
}
int maxProfit(vector<int> &prices, int n) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0, 0, n, prices, dp);
}

// tabulation

#include <bits/stdc++.h>
int maxProfit(vector<int> &prices, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(5, 0));
    for (int day = n - 1; day >= 0; day--) {
        for (int trans = 3; trans >= 0; trans--) {
            // sell
            if (trans & 1) {
                dp[day][trans] = max(prices[day] + dp[day + 1][trans + 1],
                                     dp[day + 1][trans]);
            } else {  // buy
                dp[day][trans] = max(-prices[day] + dp[day + 1][trans + 1],
                                     dp[day + 1][trans]);
            }
        }
    }
    return dp[0][0];
}

// space optimization with 2 1-D array
#include <bits/stdc++.h>
int maxProfit(vector<int> &prices, int n) {
    vector<int> prev(5, 0), cur(5, 0);
    for (int day = n - 1; day >= 0; day--) {
        for (int trans = 3; trans >= 0; trans--) {
            // sell
            if (trans & 1) {
                cur[trans] = max(prices[day] + prev[trans + 1], prev[trans]);
            } else {  // buy
                cur[trans] = max(-prices[day] + prev[trans + 1], prev[trans]);
            }
        }
        prev = cur;
    }
    return prev[0];
}

// space optimization wiht 1 1-D array

#include <bits/stdc++.h>
int maxProfit(vector<int> &prices, int n) {
    vector<int> cur(5, 0);
    for (int day = n - 1; day >= 0; day--) {
        for (int trans = 3; trans >= 0; trans--) {
            // sell
            if (trans & 1) {
                cur[trans] = max(prices[day] + cur[trans + 1], cur[trans]);
            } else {  // buy
                cur[trans] = max(-prices[day] + cur[trans + 1], cur[trans]);
            }
        }
    }
    return cur[0];
}

// k transaction

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices, int n, int k) {
    vector<int> cur(2 * k + 1, 0);
    for (int day = n - 1; day >= 0; day--) {
        for (int trans = 2 * k - 1; trans >= 0; trans--) {
            // sell
            if (trans & 1) {
                cur[trans] = max(prices[day] + cur[trans + 1], cur[trans]);
            } else {  // buy
                cur[trans] = max(-prices[day] + cur[trans + 1], cur[trans]);
            }
        }
    }
    return cur[0];
}