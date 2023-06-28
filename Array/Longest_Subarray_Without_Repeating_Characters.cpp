/*===================================================
Longest Substring Without Repeating Characters
===================================================*/

// move l after the duplicate ele. direct jump not step by step
#include <bits/stdc++.h>
int uniqueSubstrings(string input) {
    int l = 0, len = 0;
    int n = input.size();
    map<int, int> m;
    for (int r = 0; r < n; r++) {
        if (m.find(input[r]) != m.end()) {
            int dupPos = m[input[r]];
            if (dupPos >= l) {
                l = dupPos + 1;
            }
        }
        len = max(len, r - l + 1);
        m[input[r]] = r;
    }
    return len;
}