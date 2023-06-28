// unbounded knapsack
#include <bits/stdc++.h>
// memoization
int f(int i, int maxWeight, vector<int> &weight, vector<int> &value,
      vector<vector<int>> &dp) {
    if (i == 0) {
        if (weight[0] <= maxWeight) {
            return value[0] * (maxWeight / weight[0]);
        }
        return 0;
    }
    if (dp[i][maxWeight] != -1) return dp[i][maxWeight];
    int notTake = f(i - 1, maxWeight, weight, value, dp);
    int take = 0;
    if (weight[i] <= maxWeight)
        take = value[i] + f(i, maxWeight - weight[i], weight, value, dp);
    return dp[i][maxWeight] = max(take, notTake);
}

// tabulation
int unboundedKnapsack(int n, int maxWeight, vector<int> &value,
                      vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int w = weight[0]; w <= maxWeight; w++) {
        dp[0][w] = value[0] * (w / weight[0]);
    }
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int notTake = dp[i - 1][w];
            int take = 0;
            if (weight[i] <= w) take = value[i] + dp[i][w - weight[i]];
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

// space Optimiazation
int unboundedKnapsack(int n, int maxWeight, vector<int> &value,
                      vector<int> &weight) {
    vector<int> prev(maxWeight + 1, 0);
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0] * (w / weight[0]);
    }
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int notTake = prev[w];
            int take = 0;
            if (weight[i] <= w) take = value[i] + prev[w - weight[i]];
            prev[w] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}