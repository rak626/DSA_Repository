/*===================================================
4-sum-Problem
===================================================*/

// leetcode
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        if (n == 0) return ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target2 = target - (arr[i] + arr[j]);
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int pairSum = arr[l] + arr[r];

                    if (pairSum < target2)
                        l++;
                    else if (pairSum > target2)
                        r--;
                    else {
                        vector<int> qurd(4, 0);
                        qurd[0] = arr[i];
                        qurd[1] = arr[j];
                        qurd[2] = arr[l];
                        qurd[3] = arr[r];
                        ans.push_back(qurd);

                        while (l < r && arr[l] == qurd[2]) ++l;
                        while (l < r && arr[r] == qurd[3]) --r;
                    }
                }
                while (j + 1 < n && arr[j + 1] == arr[j]) ++j;
            }
            while (i + 1 < n && arr[i + 1] == arr[i]) ++i;
        }
        return ans;
    }
};

// codestudio
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int left = target - (arr[i] + arr[j]);

            if (mp.find(left) != mp.end()) {
                pair<int, int> it = mp[left];
                int k = it.first;
                int l = it.second;

                if (i != k && i != l && j != k && j != l) return "Yes";
            }
        }
    }

    return "No";
}