// Unique Paths 2 | DP on Grid with Maze Obstacles

// Recursion
int f(int row, int col, vector<vector<int>> &mat) {
  if (row >= 0 and col >= 0 and mat[row][col] == -1)
    return 0;
  if (row == 0 and col == 0)
    return 1;
  if (row < 0 or col < 0)
    return 0;
  int up = f(row - 1, col, mat);
  int left = f(row, col - 1, mat);
  return left + up;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  return f(n - 1, m - 1, mat);
}

// Memoization

int f(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp,
      int mod) {
  if (row >= 0 and col >= 0 and mat[row][col] == -1)
    return 0;
  if (row == 0 and col == 0)
    return 1;
  if (row < 0 or col < 0)
    return 0;
  if (dp[row][col] != -1)
    return dp[row][col];
  int up = f(row - 1, col, mat, dp, mod) % mod;
  int left = f(row, col - 1, mat, dp, mod) % mod;
  return dp[row][col] = (left + up) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  int mod = (int)1e9 + 7;
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n - 1, m - 1, mat, dp, mod);
}

// Tabulation

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  int mod = (int)1e9 + 7;
  vector<vector<int>> dp(n, vector<int>(m, -1));
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (mat[row][col] == -1) {
        dp[row][col] = 0;
      } else {
        if (row == 0 and col == 0)
          dp[row][col] = 1;
        else {
          int up = 0, left = 0;
          if (row > 0)
            up = dp[row - 1][col];
          if (col > 0)
            left = dp[row][col - 1];
          dp[row][col] = (left + up) % mod;
        }
      }
    }
  }
  return dp[n - 1][m - 1];
}

// Space Optimization
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  int mod = (int)1e9 + 7;
  vector<int> prev(m, 0);
  for (int row = 0; row < n; row++) {
    vector<int> cur(m);
    for (int col = 0; col < m; col++) {
      if (mat[row][col] == -1) {
        cur[col] = 0;
      } else {
        if (row == 0 and col == 0)
          cur[col] = 1;
        else {
          int up = 0, left = 0;
          if (row > 0)
            up = prev[col];
          if (col > 0)
            left = cur[col - 1];
          cur[col] = (left + up) % mod;
        }
      }
    }
    prev = cur;
  }
  return prev[m - 1];
}