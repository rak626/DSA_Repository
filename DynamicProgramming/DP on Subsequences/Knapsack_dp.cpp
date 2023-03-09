// 0/1 Knapsack

#include <bits/stdc++.h>
int f(int i, int maxWeight, vector<int> &weight, vector<int> &value,
      vector<vector<int>> &dp) {
  if (i == 0) {
    if (weight[0] <= maxWeight) {
      return value[0];
    }
    return 0;
  }
  if (dp[i][maxWeight] != -1)
    return dp[i][maxWeight];
  int notTake = f(i - 1, maxWeight, weight, value, dp);
  int take = 0;
  if (weight[i] <= maxWeight)
    take = value[i] + f(i - 1, maxWeight - weight[i], weight, value, dp);
  return dp[i][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return f(n - 1, maxWeight, weight, value, dp);
}

// tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
  for (int w = weight[0]; w <= maxWeight; w++)
    dp[0][w] = value[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= maxWeight; j++) {
      int notTake = dp[i - 1][j];
      int take = 0;
      if (weight[i] <= j)
        take = value[i] + dp[i - 1][j - weight[i]];
      dp[i][j] = max(take, notTake);
    }
  }
  return dp[n - 1][maxWeight];
}
// space optimization
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> cur(maxWeight + 1, 0);
  for (int w = weight[0]; w <= maxWeight; w++)
    cur[w] = value[0];
  for (int i = 1; i < n; i++) {
    for (int j = maxWeight; j >= 0; j--) {
      int notTake = cur[j];
      int take = 0;
      if (weight[i] <= j)
        take = value[i] + cur[j - weight[i]];
      cur[j] = max(take, notTake);
    }
  }
  return cur[maxWeight];
}