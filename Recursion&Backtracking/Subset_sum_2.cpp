// Subsets II
#include <bits/stdc++.h>
void findUniqueSubsets(vector<int> &arr, int idx, vector<int> &res,
                       vector<vector<int>> &ans) {
  ans.push_back(res);
  for (int i = idx; i < arr.size(); i++) {
    if (i != idx and arr[i] == arr[i - 1])
      continue;
    res.push_back(arr[i]);
    findUniqueSubsets(arr, i + 1, res, ans);
    res.pop_back();
  }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  vector<int> res;
  findUniqueSubsets(arr, 0, res, ans);
  // sort(ans.begin(), ans.end());
  return ans;
}