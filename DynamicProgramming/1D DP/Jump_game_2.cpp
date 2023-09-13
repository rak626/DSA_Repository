
// recursive
class Solution {
    int f(int i, int n, vector<int>& nums) {
        if (i >= n - 1) return 0;
        int mini = 1e8;
        for (int step = 1; step <= nums[i] and step < n; step++) {
            mini = min(mini, 1 + f(i + step, n, nums));
        }
        return mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        return f(0, n, nums);
    }
};

// memoization

class Solution {
    int f(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = 1e8;
        for (int step = 1; step <= nums[i] and step < n; step++) {
            mini = min(mini, 1 + f(i + step, n, nums, dp));
        }
        return dp[i] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, n, nums, dp);
    }
};

// tabulation

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 2; i >= 0; i--) {
            int mini = 1e8;
            for (int step = 1; step <= nums[i] and step < n; step++) {
                int take = 1;
                if (i + step < n) take += dp[i + step];
                mini = min(mini, take);
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};