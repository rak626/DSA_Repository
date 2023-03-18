// Longest Increasing Subsequence
#include <bits/stdc++.h>
int f(int i, int prev, int n, int arr[], vector<vector<int>> &dp) {
  if (i == n)
    return 0;
  if (dp[i][prev + 1] != -1)
    return dp[i][prev + 1];
  int len = f(i + 1, prev, n, arr, dp);
  if (prev == -1 or arr[i] > arr[prev]) {
    len = max(len, 1 + f(i + 1, i, n, arr, dp));
  }
  return dp[i][prev + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n) {
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return f(0, -1, n, arr, dp);
}

// tabulation
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int prev = -1; prev <= i; prev++) {
      int len = dp[i + 1][prev + 1];
      if (prev == -1 or arr[i] > arr[prev]) {
        len = max(len, 1 + dp[i + 1][i + 1]);
      }
      dp[i][prev + 1] = len;
    }
  }
  return dp[0][0];
}

// space optimized
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> next(n + 2, 0), cur(n + 2, 0);
  for (int i = n - 1; i >= 0; i--) {
    for (int prev = -1; prev <= i; prev++) {
      int len = next[prev + 1];
      if (prev == -1 or arr[i] > arr[prev]) {
        len = max(len, 1 + next[i + 1]);
      }
      cur[prev + 1] = len;
    }
    next = cur;
  }
  return next[0];
}

// another way of Tabulation
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> dp(n, 1);
  int maxi = 0;
  for (int i = 1; i < n; i++) {
    for (int prev = 0; prev <= i; prev++) {
      if (arr[i] > arr[prev]) {
        dp[i] = max(dp[i], 1 + dp[prev]);
      }
    }
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}
// using binary search
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> temp;
  temp.push_back(arr[0]);
  int len = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] > temp.back()) {
      temp.push_back(arr[i]);
      len++;
    } else {
      int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
      temp[ind] = arr[i];
    }
  }
  return len;
}