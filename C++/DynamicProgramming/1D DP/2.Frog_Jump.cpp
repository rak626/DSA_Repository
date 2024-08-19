// Frog Jump codestudio problem

// Recursion
#include <bits/stdc++.h>
int f(int idx, vector<int> heights) {
    if (idx == 0) return 0;
    int twoSteps = INT_MAX;
    if (idx > 1) {
        twoSteps = f(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
    }
    int oneStep = f(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);

    return min(twoSteps, oneStep);
}

int frogJump(int n, vector<int> &heights) { return f(n - 1, heights); }

// memoization

#include <bits/stdc++.h>
int f(int idx, vector<int> heights, vector<int> &dp) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];
    int twoSteps = INT_MAX;
    if (idx > 1) {
        twoSteps =
            f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
    }
    int oneStep =
        f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

    return dp[idx] = min(twoSteps, oneStep);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n + 1, -1);
    return f(n - 1, heights, dp);
}

// tabulation
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoSteps = INT_MAX;
        if (i > 1) {
            twoSteps = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(twoSteps, oneStep);
    }
    return dp[n - 1];
}

// Space Optimization
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights) {
    int prev = 0, prev2 = 0;
    for (int i = 1; i < n; i++) {
        int oneStep = prev + abs(heights[i] - heights[i - 1]);
        int twoSteps = INT_MAX;
        if (i > 1) {
            twoSteps = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curi = min(twoSteps, oneStep);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}