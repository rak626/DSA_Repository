// Edit distance

// insert - i , j-1  delete - i-1, j   replace - i-1, j-1

#include <bits/stdc++.h>
int f(int i, int j, string str1, string str2, vector<vector<int>> &dp) {
    if (j < 0) {
        if (i < 0) return 0;
        return i + 1;
    }
    if (i < 0) return j + 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (str1[i] == str2[j]) {
        return dp[i][j] = f(i - 1, j - 1, str1, str2, dp);
    }
    return dp[i][j] = 1 + min(f(i, j - 1, str1, str2, dp),
                              min(f(i - 1, j - 1, str1, str2, dp),
                                  f(i - 1, j, str1, str2, dp)));
}

int editDistance(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, str1, str2, dp);
}

// tabulation
#include <bits/stdc++.h>
int editDistance(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int j = 1; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] =
                    1 + min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
            }
        }
    }
    return dp[n][m];
}

// space optimization

#include <bits/stdc++.h>
int editDistance(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 1; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        cur[0] = i;
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cur[j] = prev[j - 1];
            } else {
                cur[j] = 1 + min(cur[j - 1], min(prev[j - 1], prev[j]));
            }
        }
        prev = cur;
    }
    return prev[m];
}
