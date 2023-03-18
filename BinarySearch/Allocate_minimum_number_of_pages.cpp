// Allocate Minimum Number of Pages

#include <bits/stdc++.h>
bool isAllocated(long long bar, int n, vector<int> &time) {
  int days = 1;
  long long timeConsumed = 0;
  for (int i = 0; i < time.size(); i++) {
    if ((long long)time[i] > bar)
      return false;
    if (timeConsumed + (long long)time[i] > bar) {
      days++;
      timeConsumed = (long long)time[i];
    } else {
      timeConsumed += (long long)time[i];
    }
  }
  if (days > n)
    return false;
  return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    sum += time[i];
  }
  long long res = 0;
  long long low = (long long)time[0], high = sum;
  while (low <= high) {
    long long mid = low + ((high - low) >> 1);
    if (isAllocated(mid, n, time)) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return;
}