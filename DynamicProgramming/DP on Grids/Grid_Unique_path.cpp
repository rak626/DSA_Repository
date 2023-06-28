// Grid Unique Paths

// Recursion

int f(int row, int col) {
    if (row == 0 and col == 0) return 1;
    if (row < 0 or col < 0) return 0;
    int up = f(row - 1, col);
    int left = f(row, col - 1);
    return left + up;
}

int uniquePaths(int m, int n) { return f(m - 1, n - 1); }

// Memoization

#include <bits/stdc++.h>

int f(int row, int col, vector<vector<int>> &dp) {
    if (row == 0 and col == 0) return 1;
    if (row < 0 or col < 0) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    int up = f(row - 1, col, dp);
    int left = f(row, col - 1, dp);
    return dp[row][col] = left + up;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

// Tabulation
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (row == 0 and col == 0)
                dp[row][col] = 1;
            else {
                int up = 0, left = 0;
                if (row > 0) up = dp[row - 1][col];
                if (col > 0) left = dp[row][col - 1];
                dp[row][col] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimization
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);
    for (int row = 0; row < m; row++) {
        vector<int> cur(n);
        for (int col = 0; col < n; col++) {
            if (row == 0 and col == 0)
                cur[col] = 1;
            else {
                int up = 0, left = 0;
                if (row > 0) up = prev[col];
                if (col > 0) left = cur[col - 1];
                cur[col] = left + up;
            }
        }
        prev = cur;
    }
    return prev[n - 1];
}