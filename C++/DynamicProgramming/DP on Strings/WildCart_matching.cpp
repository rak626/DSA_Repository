// Wildcard Matching

class Solution {
    bool f(int i, int j, string p, string s, vector<vector<int>> &dp) {
        if (i < 0 and j < 0) return true;
        if (i < 0 and j >= 0) return false;
        if (j < 0 and i >= 0) {
            for (int x = 0; x <= i; x++) {
                if (p[x] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[i] == s[j] or p[i] == '?') {
            return dp[i][j] = f(i - 1, j - 1, p, s, dp);
        } else if (p[i] == '*') {
            return dp[i][j] = f(i - 1, j, p, s, dp) or f(i, j - 1, p, s, dp);
        }
        return dp[i][j] = 0;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n - 1, m - 1, p, s, dp);
    }
};

// tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int x = 1; x <= i; x++) {
                if (p[x - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] or p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

// space optimized
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<bool> prev(m + 1, false), cur(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int x = 1; x <= i; x++) {
                if (p[x - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] or p[i - 1] == '?') {
                    cur[j] = prev[j - 1];
                } else if (p[i - 1] == '*') {
                    cur[j] = prev[j] or cur[j - 1];
                } else {
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};