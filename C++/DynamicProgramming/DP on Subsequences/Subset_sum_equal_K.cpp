// Subset Sum Equal To K

// recursion
#include <bits/stdc++.h>

bool f(int idx, int target, vector<int> &arr) {
    if (target == 0) return true;
    if (idx == 0) return arr[0] == target;
    int take = false;
    if (target >= arr[idx]) take = f(idx - 1, target - arr[idx], arr);
    int notTake = f(idx - 1, target, arr);
    return take or notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) { return f(n - 1, k, arr); }

// memoization

#include <bits/stdc++.h>

bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (idx == 0) return arr[0] == target;
    if (dp[idx][target] != -1) return dp[idx][target];
    int take = false;
    if (target >= arr[idx]) take = f(idx - 1, target - arr[idx], arr, dp);
    int notTake = f(idx - 1, target, arr, dp);
    return dp[idx][target] = (take or notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// tabulation

#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = false;
            if (target >= arr[i]) take = dp[i - 1][target - arr[i]];
            int notTake = dp[i - 1][target];
            dp[i][target] = (take or notTake);
        }
    }
    return dp[n - 1][k];
}

// space optimization
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = false;
            if (target >= arr[i]) take = prev[target - arr[i]];
            int notTake = prev[target];
            cur[target] = (take or notTake);
        }
        prev = cur;
    }
    return prev[k];
}