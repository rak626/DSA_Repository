// Target Sum

// by using:: concept of count partition

/*right now target = d;
s1 contains all pos, s2 contains all neg
s1 - s2 = d*/

#include <bits/stdc++.h>
int findWays(vector<int> &nums, int tar) {
  int n = nums.size();
  vector<int> prev(tar + 1, 0);
  if (nums[0] == 0) {
    prev[0] = 2;
  } else {
    prev[0] = 1;
  }
  if (nums[0] and nums[0] <= tar)
    prev[nums[0]] = 1;
  for (int i = 1; i < n; i++) {
    vector<int> cur(tar + 1, 0);
    for (int j = 0; j <= tar; j++) {
      int notPick = prev[j];
      int pick = 0;
      if (j >= nums[i])
        pick = prev[j - nums[i]];
      cur[j] = (pick + notPick);
    }
    prev = cur;
  }
  return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
  int totalSum = 0;
  for (auto x : arr)
    totalSum += x;
  int target = (totalSum - d);
  if (target < 0 or target & 1)
    return 0;
  return findWays(arr, target / 2);
}
int targetSum(int n, int target, vector<int> &arr) {
  return countPartitions(n, target, arr);
}
