// 3 sum

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans;
    if (n == 0 or n == 1 or n == 2) return ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int sum = K - arr[i];
        int l = i + 1, h = n - 1;
        while (l < h) {
            int pairSum = arr[l] + arr[h];
            if (pairSum == sum) {
                ans.push_back({arr[i], arr[l], arr[h]});
            }
            if (pairSum < sum) {
                while (l < h and arr[l] == arr[l + 1]) l++;
                l++;
            } else {
                while (l < h and arr[h] == arr[h - 1]) h--;
                h--;
            }
        }
        while (i < n and arr[i] == arr[i + 1]) i++;
    }
    return ans;
}