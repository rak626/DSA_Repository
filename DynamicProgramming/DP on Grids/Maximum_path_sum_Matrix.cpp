// Maximum Path Sum in the matrix

// recursion
#include <bits/stdc++.h>
int f(int i, int j, vector<vector<int>> &matrix) {
    if (j < 0 or j > matrix[0].size() - 1) return -1e8;
    if (i == 0) return matrix[0][j];

    int up = matrix[i][j] + f(i - 1, j, matrix);
    int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, matrix);
    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e8;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, f(n - 1, j, matrix));
    }
    return maxi;
}

// memoization

#include <bits/stdc++.h>
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (j < 0 or j >= matrix[0].size()) return -1e8;
    if (i == 0) return matrix[0][j];
    if (dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + f(i - 1, j, matrix, dp);
    int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, f(n - 1, j, matrix, dp));
    }
    return maxi;
}

// tabulation

#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0] = matrix[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = -1e9;
            if (j - 1 >= 0) leftDiagonal = matrix[i][j] + dp[i - 1][j - 1];
            int rightDiagonal = -1e9;
            if (j + 1 < m) rightDiagonal = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }
    int maxi = -1e9;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}

// space optimization

#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m, -1);
    prev = matrix[0];
    for (int i = 1; i < n; i++) {
        vector<int> cur(m, -1);
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = -1e9;
            if (j - 1 >= 0) leftDiagonal = matrix[i][j] + prev[j - 1];
            int rightDiagonal = -1e9;
            if (j + 1 < m) rightDiagonal = matrix[i][j] + prev[j + 1];

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }
    int maxi = -1e9;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}