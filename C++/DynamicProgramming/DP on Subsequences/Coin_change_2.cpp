// coin Change 2

class Solution {
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return 1;
            return 0;
        }
        if (dp[i][amount] != -1) return dp[i][amount];
        int notTake = f(i - 1, amount, coins, dp);
        int take = 0;
        if (coins[i] <= amount) take = 1 + f(i, amount - coins[i], coins, dp);
        return dp[i][amount] = take + notTake;
    }

public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return ans;
    }
};

// tabulation with space optimization

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) prev[j] = 1;
        }
        for (int i = 1; i < n; i++) {
            vector<int> cur(amount + 1, 0);
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = 0;
                if (coins[i] <= j) take = cur[j - coins[i]];
                cur[j] = take + notTake;
            }
            prev = cur;
        }
        int ans = prev[amount];
        return ans;
    }
};