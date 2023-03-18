// Maximum sum of non-adjacent elements

// Recursion

int f(int idx, vector<int> &nums) {
  if (idx == 0)
    return nums[0];
  if (idx < 0)
    return 0;
  int pick = nums[idx] + f(idx - 2, nums);
  int nonPick = f(idx - 1, nums);

  return max(pick, nonPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
  int n = nums.size();
  return f(n - 1, nums);
}

// memoization

int f(int idx, vector<int> &nums, vector<int> &dp) {
  if (idx == 0)
    return nums[0];
  if (idx < 0)
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int pick = nums[idx] + f(idx - 2, nums, dp);
  int nonPick = f(idx - 1, nums, dp);

  return dp[idx] = max(pick, nonPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n + 1, -1);
  return f(n - 1, nums, dp);
}

// Tabulation

int maximumNonAdjacentSum(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n + 1, -1);
  dp[0] = nums[0];
  for (int i = 1; i < n; i++) {
    int pick = nums[i];
    if (i > 1) {
      pick += dp[i - 2];
    }
    int nonPick = dp[i - 1];
    dp[i] = max(pick, nonPick);
  }
  return dp[n - 1];
}

// space optimization

int maximumNonAdjacentSum(vector<int> &nums) {
  int n = nums.size();
  int prev = nums[0], prev2 = 0;
  for (int i = 1; i < n; i++) {
    int pick = nums[i];
    if (i > 1) {
      pick += prev2;
    }
    int nonPick = prev;
    int curi = max(pick, nonPick);
    prev2 = prev;
    prev = curi;
  }
  return prev;
}