/*===================================================
Longest Consecutive Sequence
===================================================*/

#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    for (auto x : arr) s.insert(x);
    int maxLen = 0;
    for (auto x : arr) {
        if (s.find(x - 1) == s.end()) {
            int cnt = 1, num = x + 1;
            while (s.find(num) != s.end()) {
                cnt++;
                num++;
            }
            maxLen = max(cnt, maxLen);
        }
    }
    return maxLen;
}
