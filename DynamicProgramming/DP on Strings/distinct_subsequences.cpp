// Subsequence Counting

// memoization
#include <bits/stdc++.h>
int mod = (int)1e9 + 7;
int f(int i, int j, string t, string s, vector<vector<int>> &dp) {
    if (j < 0) return 1;
    if (i < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (t[i] == s[j]) {
        return dp[i][j] = (f(i - 1, j - 1, t, s, dp) % mod +
                           f(i - 1, j, t, s, dp) % mod) %
                          mod;
    }
    return dp[i][j] = f(i - 1, j, t, s, dp) % mod;
}

int subsequenceCounting(string &t, string &s, int n, int m) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, t, s, dp);
}

// tabulation
#include <bits/stdc++.h>
int mod = (int)1e9 + 7;
int subsequenceCounting(string &t, string &s, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            } else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }
    return dp[n][m];
}

// space optimization 1d array
#include <bits/stdc++.h>
int mod = (int)1e9 + 7;
int subsequenceCounting(string &t, string &s, int n, int m) {
    vector<int> cur(m + 1, 0);
    cur[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            if (t[i - 1] == s[j - 1]) {
                cur[j] = (cur[j - 1] + cur[j]) % mod;
            } else {
                cur[j] = cur[j] % mod;
            }
        }
    }
    return cur[m];
}