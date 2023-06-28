/*===================================================
Pair Sum 2-sum
===================================================*/

#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        int fkey = s - arr[i];
        if (m.find(fkey) != m.end()) {
            for (int j = 0; j < m[fkey]; j++) {
                vector<int> res(2);
                res[0] = fkey > arr[i] ? arr[i] : fkey;
                res[1] = fkey > arr[i] ? fkey : arr[i];
                ans.push_back(res);
            }
        }
        m[arr[i]]++;
    }
    sort(ans.begin(), ans.end());  // as per question requirement not needed
    return ans;
}