/*===================================================
Longest Subarray Zero Sum
===================================================*/

#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector<int> arr) {
  unordered_map<int, int> m;
  int maxLen = 0, sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == 0) {
      maxLen = max(maxLen, i + 1);
    } else {
      if (m.find(sum) != m.end()) {
        maxLen = max(maxLen, i - m[sum]);
      } else {
        m[sum] = i;
      }
    }
  }
  return maxLen;
}