/*=====================
Grid Unique Paths
=======================*/

// by recursion
#include <bits/stdc++.h>

int findPaths(int i, int j, int m, int n) {
    if (i == m - 1 and j == n - 1) return 1;
    if (i >= m or j >= n) return 0;
    return findPaths(i + 1, j, m, n) + findPaths(i, j + 1, m, n);
}

int uniquePaths(int m, int n) { return findPaths(0, 0, m, n); }

// by DP
#include <bits/stdc++.h>

int findPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if (i == m - 1 and j == n - 1) return 1;
    if (i >= m or j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] =
               findPaths(i + 1, j, m, n, dp) + findPaths(i, j + 1, m, n, dp);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return findPaths(0, 0, m, n, dp);
}

// by Combinatorics
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = n < m ? n - 1 : m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}