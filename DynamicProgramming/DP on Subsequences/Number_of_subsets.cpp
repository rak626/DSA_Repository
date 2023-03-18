// Number Of Subsets

#include <bits/stdc++.h>
int f(int i, int tar, vector<int> &nums, vector<vector<int>> &dp) {
  if (i == 0) {
    if (nums[0] == 0 and tar == 0)
      return 2;
    else if (tar == 0 or nums[0] == tar)
      return 1;
    else
      return 0;
  }
  if (dp[i][tar] != -1)
    return dp[i][tar];
  int notPick = f(i - 1, tar, nums, dp);
  int pick = 0;
  if (tar >= nums[i])
    pick = f(i - 1, tar - nums[i], nums, dp);
  return dp[i][tar] = pick + notPick;
}

int findWays(vector<int> &nums, int tar) {
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
  return f(n - 1, tar, nums, dp);
}

// tabulation

#include <bits/stdc++.h>
int findWays(vector<int> &nums, int tar) {
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
  if (nums[0] == 0) {
    dp[0][0] = 2;
  } else {
    dp[0][0] = 1;
  }
  if (nums[0] and nums[0] <= tar)
    dp[0][nums[0]] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= tar; j++) {
      int notPick = dp[i - 1][j];
      int pick = 0;
      if (j >= nums[i])
        pick = dp[i - 1][j - nums[i]];
      dp[i][j] = pick + notPick;
    }
  }
  return dp[n - 1][tar];
}

// space optimization
#include <bits/stdc++.h>
int findWays(vector<int> &nums, int tar) {
  int n = nums.size();
  vector<int> prev(tar + 1, 0);
  if (nums[0] == 0) {
    prev[0] = 2;
  } else {
    prev[0] = 1;
  }
  if (nums[0] and nums[0] <= tar)
    prev[nums[0]] = 1;
  for (int i = 1; i < n; i++) {
    vector<int> cur(tar + 1, 0);
    for (int j = 0; j <= tar; j++) {
      int notPick = prev[j];
      int pick = 0;
      if (j >= nums[i])
        pick = prev[j - nums[i]];
      cur[j] = pick + notPick;
    }
    prev = cur;
  }
  return prev[tar];
}