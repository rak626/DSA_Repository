// Matrix Chain Multiplication

// tabulation
#include <bits/stdc++.h>
int matrixMultiplication(vector<int> &arr, int n) {
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = n - 2; i >= 1; i--) {
    for (int j = i + 1; j < n; j++) {
      int mini = 1e9;
      for (int k = i; k < j; k++) {
        int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        mini = min(steps, mini);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][n - 1];
}


//two 