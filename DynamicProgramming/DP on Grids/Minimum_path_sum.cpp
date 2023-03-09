// Minimum Path Sum

// Recursion
#include <bits/stdc++.h>
int f(int row, int col, vector<vector<int>> &grid) {
  if (row == 0 and col == 0)
    return grid[row][col];
  if (row < 0 or col < 0)
    return 1e9;
  int up = grid[row][col] + f(row - 1, col, grid);
  int down = grid[row][col] + f(row, col - 1, grid);
  return min(up, down);
}
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  return f(n - 1, m - 1, grid);
}

// Memoization

#include <bits/stdc++.h>
int f(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if (row == 0 and col == 0)
    return grid[row][col];
  if (row < 0 or col < 0)
    return 1e9;
  if (dp[row][col] != -1)
    return dp[row][col];
  int up = grid[row][col] + f(row - 1, col, grid, dp);
  int down = grid[row][col] + f(row, col - 1, grid, dp);
  return dp[row][col] = min(up, down);
}
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n - 1, m - 1, grid, dp);
}

// Tabulation

#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (row == 0 and col == 0)
        dp[row][col] = grid[0][0];
      else {
        int up = 1e9, left = 1e9;
        if (row > 0)
          up = grid[row][col] + dp[row - 1][col];
        if (col > 0)
          left = grid[row][col] + dp[row][col - 1];
        dp[row][col] = min(left, up);
      }
    }
  }
  return dp[n - 1][m - 1];
}

// Space Optimization

#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vector<int> prev(m, 0);
  for (int row = 0; row < n; row++) {
    vector<int> cur(m);
    for (int col = 0; col < m; col++) {
      if (row == 0 and col == 0)
        cur[col] = grid[0][0];
      else {
        int up = 1e9, left = 1e9;
        if (row > 0)
          up = grid[row][col] + prev[col];
        if (col > 0)
          left = grid[row][col] + cur[col - 1];
        cur[col] = min(left, up);
      }
    }
    prev = cur;
  }
  return prev[m - 1];
}