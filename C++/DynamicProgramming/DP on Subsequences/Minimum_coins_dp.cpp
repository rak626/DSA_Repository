// Minimum Coins | DP on Subsequences | Infinite Supplies Pattern

// recursion / memoization
class Solution {
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e8;
        }
        if (dp[i][amount] != -1) return dp[i][amount];
        int notTake = f(i - 1, amount, coins, dp);
        int take = 1e8;
        if (coins[i] <= amount) take = 1 + f(i, amount - coins[i], coins, dp);
        return dp[i][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return ans == 1e8 ? -1 : ans;
    }
};

// tabulation
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e8;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = 1e8;
                if (coins[i] <= j) take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }
        int ans = dp[n - 1][amount];
        return ans == 1e8 ? -1 : ans;
    }
};

// space optimization

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                prev[j] = j / coins[0];
            else
                prev[j] = 1e8;
        }
        for (int i = 1; i < n; i++) {
            vector<int> cur(amount + 1, 0);
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = 1e8;
                if (coins[i] <= j) take = 1 + cur[j - coins[i]];
                cur[j] = min(take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        return ans >= 1e8 ? -1 : ans;
    }
};