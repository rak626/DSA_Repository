/*===================================
Missing and repeating numbers
===================================*/

// using sum and sqsum method (integer out of bound may be happen)
#include <bits/stdc++.h>
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
  // Write your code here
  pair<int, int> p;
  long long sum = (long long)n * (n + 1) / 2;
  long long sqsum = (long long)n * (n + 1) * (2 * n + 1) / 6;
  long long temp, miss, rept;
  for (long long i = 0; i < n; i++) {
    temp = (long long)arr[i];
    sum -= temp;
    sqsum -= temp * temp;
  }
  miss = (sum + (sqsum / sum)) / 2;
  rept = miss - sum;
  p.first = miss;
  p.second = rept;
  return p;
}

// using xor method (most optimized) and not modified the actual array
#include <bits/stdc++.h>
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
  int xor1 = 0;
  for (int i = 0; i < n; i++) {
    xor1 ^= arr[i];
  }
  for (int i = 1; i <= n; i++) {
    xor1 ^= i;
  }
  int setbits = xor1 & ~(xor1 - 1);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (setbits & arr[i]) {
      x ^= arr[i];
    } else {
      y ^= arr[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (setbits & i) {
      x ^= i;
    } else {
      y ^= i;
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    return {y, x};
  }
  return {x, y};
}