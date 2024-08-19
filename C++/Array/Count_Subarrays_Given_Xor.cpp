/*===================================================
Count Subarrays with Given XOR
===================================================*/

// XR = Y ^ K => Y = XR ^ K
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x) {
    map<int, int> m;
    int cnt = 0;
    int preXor = 0;
    for (auto it : arr) {
        preXor = preXor ^ it;
        if (preXor == x) cnt++;
        int y = preXor ^ x;
        if (m.find(y) != m.end()) {
            cnt += m[y];
        }
        m[preXor]++;
    }
    return cnt;
}