/*===================================
Find Duplicate in Array
===================================*/

// floyed's algorithm

#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n) {
    int fast = arr[0], slow = arr[0];
    do {
        fast = arr[arr[fast]];
        slow = arr[slow];
    } while (fast != slow);

    fast = arr[0];
    while (fast != slow) {
        fast = arr[fast];
        slow = arr[slow];
    }
    return fast;
}
