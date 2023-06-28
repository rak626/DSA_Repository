// Rod cutting problem

// memoization
#include <bits/stdc++.h>
int f(int i, int length, vector<int> &price, vector<vector<int>> &dp) {
    if (i == 0) {
        if (length >= 1) return price[0] * length;
        return 0;
    }
    if (dp[i][length] != -1) return dp[i][length];
    int notTake = f(i - 1, length, price, dp);
    int take = 0;
    if (length >= i + 1) take = price[i] + f(i, length - (i + 1), price, dp);
    return dp[i][length] = max(take, notTake);
}
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// tabulation space optimization

#include <bits/stdc++.h>
int cutRod(vector<int> &price, int n) {
    vector<int> cur(n + 1, 0);
    for (int l = 1; l <= n; l++) {
        cur[l] = price[0] * l;
    }
    for (int i = 1; i < n; i++) {
        for (int length = 1; length <= n; length++) {
            int notTake = cur[length];
            int take = 0;
            if (length >= i + 1) take = price[i] + cur[length - (i + 1)];
            cur[length] = max(take, notTake);
        }
    }
    return cur[n];
}