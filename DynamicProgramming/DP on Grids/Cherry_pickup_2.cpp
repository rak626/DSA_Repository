// Cherry Pickup II | 3D DP Made Easy | DP On Grids

// recursion
#include <bits/stdc++.h>
int f(int i, int ja, int jb, int r, int c, vector<vector<int>> &grid) {
    if (ja < 0 or ja >= c or jb < 0 or jb >= c) return -1e8;
    if (i == r - 1) {
        if (ja == jb) {
            return grid[i][jb];
        }
        return grid[i][ja] + grid[i][jb];
    }
    int maxi = 0;
    for (int dja = -1; dja <= 1; dja++) {
        for (int djb = -1; djb <= 1; djb++) {
            int value = 0;
            if (ja == jb) {
                value = grid[i][ja];
            } else {
                value = grid[i][ja] + grid[i][jb];
            }
            value += f(i + 1, ja + dja, jb + djb, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0, 0, c - 1, r, c, grid);
}

// memoization

#include <bits/stdc++.h>
int f(int i, int ja, int jb, int r, int c, vector<vector<int>> &grid,
      vector<vector<vector<int>>> &dp) {
    if (ja < 0 or ja >= c or jb < 0 or jb >= c) return -1e8;
    if (i == r - 1) {
        if (ja == jb) {
            return grid[i][jb];
        }
        return grid[i][ja] + grid[i][jb];
    }
    if (dp[i][ja][jb] != -1) return dp[i][ja][jb];
    int maxi = 0;
    for (int dja = -1; dja <= 1; dja++) {
        for (int djb = -1; djb <= 1; djb++) {
            int value = 0;
            if (ja == jb) {
                value = grid[i][ja];
            } else {
                value = grid[i][ja] + grid[i][jb];
            }
            value += f(i + 1, ja + dja, jb + djb, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][ja][jb] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,
                                   vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp);
}

// tabulation

#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,
                                   vector<vector<int>>(c, vector<int>(c, -1)));
    for (int ja = 0; ja < c; ja++) {
        for (int jb = 0; jb < c; jb++) {
            if (ja == jb)
                dp[r - 1][ja][jb] = grid[r - 1][ja];
            else
                dp[r - 1][ja][jb] = grid[r - 1][ja] + grid[r - 1][jb];
        }
    }
    for (int i = r - 2; i >= 0; i--) {
        for (int ja = 0; ja < c; ja++) {
            for (int jb = 0; jb < c; jb++) {
                int maxi = -1e8;
                for (int dja = -1; dja <= 1; dja++) {
                    for (int djb = -1; djb <= 1; djb++) {
                        int value = 0;
                        if (ja == jb)
                            value = grid[i][ja];
                        else
                            value = grid[i][ja] + grid[i][jb];
                        if (ja + dja < c and ja + dja >= 0 and jb + djb < c and
                            jb + djb >= 0)
                            value += dp[i + 1][ja + dja][jb + djb];
                        maxi = max(maxi, value);
                    }
                }
                dp[i][ja][jb] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}

// space optimization

#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> prev(c, vector<int>(c, -1));
    for (int ja = 0; ja < c; ja++) {
        for (int jb = 0; jb < c; jb++) {
            if (ja == jb)
                prev[ja][jb] = grid[r - 1][ja];
            else
                prev[ja][jb] = grid[r - 1][ja] + grid[r - 1][jb];
        }
    }
    for (int i = r - 2; i >= 0; i--) {
        vector<vector<int>> cur(c, vector<int>(c, -1));
        for (int ja = 0; ja < c; ja++) {
            for (int jb = 0; jb < c; jb++) {
                int maxi = -1e8;
                for (int dja = -1; dja <= 1; dja++) {
                    for (int djb = -1; djb <= 1; djb++) {
                        int value = 0;
                        if (ja == jb)
                            value = grid[i][ja];
                        else
                            value = grid[i][ja] + grid[i][jb];
                        if (ja + dja < c and ja + dja >= 0 and jb + djb < c and
                            jb + djb >= 0)
                            value += prev[ja + dja][jb + djb];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                cur[ja][jb] = maxi;
            }
        }
        prev = cur;
    }
    return prev[0][c - 1];
}