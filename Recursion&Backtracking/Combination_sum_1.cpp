// Return Subsets Sum to K or Combination Sum I

// leetcode Sol
class Solution {
public:
    void findSubset(vector<int> &arr, int idx, int k, vector<int> &ds,
                    vector<vector<int>> &ans) {
        if (idx == arr.size()) {
            if (k == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[idx] <= k) {
            ds.push_back(arr[idx]);
            findSubset(arr, idx, k - arr[idx], ds, ans);
            ds.pop_back();
        }
        findSubset(arr, idx + 1, k, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        findSubset(arr, 0, k, ds, ans);
        return ans;
    }
};

// codestudio sol

#include <bits/stdc++.h>

void findSubset(vector<int> &arr, int idx, int k, vector<int> &ds,
                vector<vector<int>> &ans) {
    if (idx == arr.size()) {
        if (k == 0) {
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(arr[idx]);
    findSubset(arr, idx + 1, k - arr[idx], ds, ans);
    ds.pop_back();
    findSubset(arr, idx + 1, k, ds, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<int> ds;
    vector<vector<int>> ans;
    // sort(arr.begin(), arr.end());
    findSubset(arr, 0, k, ds, ans);
    return ans;
}