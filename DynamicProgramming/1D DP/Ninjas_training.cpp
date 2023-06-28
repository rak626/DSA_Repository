// Ninja’s Training

// Recursion
int f(int idx, int last, vector<vector<int>> &points) {
    if (idx == 0) {
        int maxPoint = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxPoint = max(maxPoint, points[idx][i]);
            }
        }
        return maxPoint;
    }

    int maxPoint = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            maxPoint =
                max(maxPoint, f(idx - 1, i, points, dp) + points[idx][i]);
        }
    }
    return maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    return f(n - 1, 3, points);
}

// Memoization
int f(int idx, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (idx == 0) {
        int maxPoint = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxPoint = max(maxPoint, points[idx][i]);
            }
        }
        return maxPoint;
    }
    if (dp[idx][last] != -1) return dp[idx][last];
    int maxPoint = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            maxPoint =
                max(maxPoint, f(idx - 1, i, points, dp) + points[idx][i]);
        }
    }
    return dp[idx][last] = maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int idx = 1; idx < n; idx++) {
        for (int last = 0; last < 4; last++) {
            dp[idx][last] = 0;
            int maxPoint = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    int point = points[idx][i] + dp[idx - 1][i];
                    maxPoint = max(maxPoint, point);
                }
            }
            dp[idx][last] = maxPoint;
        }
    }
    return dp[n - 1][3];
}

// Space Optimized

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> dp(4);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int idx = 1; idx < n; idx++) {
        vector<int> cur(4);
        for (int last = 0; last < 4; last++) {
            cur[last] = 0;
            int maxPoint = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    int point = points[idx][i] + dp[i];
                    maxPoint = max(maxPoint, point);
                }
            }
            cur[last] = maxPoint;
        }
        dp = cur;
    }
    return dp[3];
}