// Partition a set into two subsets such that the difference of subset sums is
// minimum.

#include <bits/stdc++.h>
int findSubSetPartitionSum(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = false;
            if (target >= arr[i]) take = prev[target - arr[i]];
            int notTake = prev[target];
            cur[target] = (take or notTake);
        }
        prev = cur;
    }
    int mini = INT_MAX;
    for (int j = 0; j <= k / 2; j++) {
        if (prev[j]) {
            mini = min(mini, abs(k - j - j));
        }
    }
    return mini;
}
int minSubsetSumDifference(vector<int> &arr, int n) {
    int totalSum = 0;
    for (auto x : arr) totalSum += x;
    return findSubSetPartitionSum(n, totalSum, arr);
}