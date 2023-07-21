// Trapping Rain Water

#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n) {
    long ans = 0;
    if (n == 0) return ans;
    long leftMax[n], rightMax[n];
    long preMax = INT_MIN, postMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        preMax = max(preMax, arr[i]);
        leftMax[i] = preMax;
        postMax = max(postMax, arr[n - 1 - i]);
        rightMax[n - 1 - i] = postMax;
    }
    for (int i = 0; i < n; i++) {
        ans += min(leftMax[i], rightMax[i]) - arr[i];
    }
    return ans;
}