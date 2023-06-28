
// Climbing Stairs

// recursion
class Solution {
    int f(int idx) {
        if (idx == 0) return 1;
        if (idx == 1) return 1;
        int left = f(idx - 1);
        int right = f(idx - 2);
        return left + right;
    }

public:
    int climbStairs(int n) { return f(n); }
};

// memoization

class Solution {
    int f(int idx, vector<int> &dp) {
        if (idx == 0) return 1;
        if (idx == 1) return 1;
        if (dp[idx] != -1) return dp[idx];
        int left = f(idx - 1, dp);
        int right = f(idx - 2, dp);
        return dp[idx] = left + right;
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

// Tabulation

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int left = dp[i - 1];
            int right = dp[i - 2];
            dp[i] = right + left;
        }
        return dp[n];
    }
};

// tabulation with Space Optimization

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};