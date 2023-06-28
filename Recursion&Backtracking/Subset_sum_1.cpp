// Subset Sum
#include <bits/stdc++.h>

void findSum(vector<int> &num, int idx, int sum, vector<int> &ans) {
    if (idx == num.size()) {
        ans.push_back(sum);
        return;
    }

    findSum(num, idx + 1, sum, ans);
    findSum(num, idx + 1, sum + num[idx], ans);
}

vector<int> subsetSum(vector<int> &num) {
    vector<int> ans;
    findSum(num, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}