// Combination Sum II

#include <bits/stdc++.h>

void findSum(vector<int> &arr, int idx, int target, vector<int> &ds,
             vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        if (i > idx and arr[i] == arr[i - 1]) continue;
        if (arr[i] > target) break;
        ds.push_back(arr[i]);
        findSum(arr, i + 1, target - arr[i], ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findSum(arr, 0, target, ds, ans);
    return ans;
}