// Triangle
// Recursion
int f(int i, int j, vector<vector<int>> &triangle) {
  if (i == triangle.size())
    return 0;
  int down = triangle[i][j] + f(i + 1, j, triangle);
  int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle);
  return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n) {
  return f(0, 0, triangle);
}

// Memoization

int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
  if (i == triangle.size())
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int down = triangle[i][j] + f(i + 1, j, triangle, dp);
  int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, dp);
  return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n) {
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return f(0, 0, triangle, dp);
}

// tabulation

int minimumPathSum(vector<vector<int>> &triangle, int n) {
  vector<vector<int>> dp(n, vector<int>(n, -1));
  dp[n - 1] = triangle[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int down = triangle[i][j] + dp[i + 1][j];
      int diagonal = triangle[i][j] + dp[i + 1][j + 1];
      dp[i][j] = min(down, diagonal);
    }
  }
  return dp[0][0];
}

// space optimization

int minimumPathSum(vector<vector<int>> &triangle, int n) {
  vector<int> prev(n, -1);
  prev = triangle[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    vector<int> cur(n, -1);
    for (int j = i; j >= 0; j--) {
      int down = triangle[i][j] + prev[j];
      int diagonal = triangle[i][j] + prev[j + 1];
      cur[j] = min(down, diagonal);
    }
    prev = cur;
  }
  return prev[0];
}