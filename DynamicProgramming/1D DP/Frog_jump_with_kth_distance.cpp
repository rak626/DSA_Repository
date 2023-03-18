// Frog Jump with K Distance

// Recursion
#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int> &heights, int k) {
  if (idx == 0)
    return 0;
  int minStep = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if (idx - i >= 0) {
      int steps = f(idx - i, heights, k) + abs(heights[idx] - heights[idx - i]);
      minStep = min(minStep, steps);
    }
  }
  return minStep;
}

int frogJumpKDistance(int n, vector<int> &heights, int k) {
  return f(n - 1, heights, k);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  cout << frogJumpKDistance(n, heights, k) << endl;
}

// memoization

#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int> &heights, int k, vector<int> &dp) {
  if (idx == 0)
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int minStep = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if (idx - i >= 0) {
      int steps =
          f(idx - i, heights, k, dp) + abs(heights[idx] - heights[idx - i]);
      minStep = min(minStep, steps);
    }
  }
  return dp[idx] = minStep;
}

int frogJumpKDistance(int n, vector<int> &heights, int k) {
  vector<int> dp(n + 1, -1);
  return f(n - 1, heights, k, dp);
}

// tabulation

int frogJumpKDistance(int n, vector<int> &heights, int k) {
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int minStep = INT_MAX;
    for (int j = k; j >= 1; j--) {
      if (i - j >= 0) {
        int steps = dp[i - j] + abs(heights[i] - heights[i - j]);
        minStep = min(minStep, steps);
      }
    }
    dp[i] = minStep;
  }
  return dp[n - 1];
}