#include <bits/stdc++.h>

int dp[21][180][2];
long long int solve(string &str, int pos, int sum, int res) {
    if (pos >= str.length()) {
        return dp[pos][sum][res] = sum == 10;
    }
    if (dp[pos][sum][res] != -1) {
        return dp[pos][sum][res];
    }
    long long int ans = 0;
    if (res == 1) {
        for (int i = 0; i <= str[pos] - '0'; i++) {
            if (i == str[pos] - '0') {
                ans += solve(str, pos + 1, sum + i, 1);
            } else {
                ans += solve(str, pos + 1, sum + i, 0);
            }
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            ans += solve(str, pos + 1, sum + i, 0);
        }
    }
    return dp[pos][sum][res] = ans;
}

long long nthNumberWithSum10(long long n) {
    long long int s = 19;
    long long int e = LONG_MAX;
    long long int ans = 0;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        string str = to_string(mid);
        memset(dp, -1, sizeof(dp));
        long long int cnt = solve(str, 0, 0, 1);
        if (cnt >= n) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

