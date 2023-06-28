// Minimum Number of Platforms

#include <bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 0, j = 0;
    int cnt = 0, best = 0;
    while (i < n and j < n) {
        if (at[i] <= dt[j]) {
            cnt++, i++;
        } else {
            cnt--, j++;
        }
        best = max(best, cnt);
    }
    return best;
}