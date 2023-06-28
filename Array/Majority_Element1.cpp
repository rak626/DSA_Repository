/*==================================
Majority element (> n /2 times)
==================================*/

#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n) {
    int ele = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            ele = arr[i];
        }
        if (arr[i] == ele)
            cnt++;
        else
            cnt--;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ele == arr[i]) {
            cnt++;
        }
    }
    if (cnt > (n / 2)) return ele;
    return -1;
}