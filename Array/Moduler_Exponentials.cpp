/*================================
Modular Exponentiation
================================*/

// codestudio code using mod
// using fast exponentiation
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
    long ans = 1;
    long xx = x;
    while (n > 0) {
        if (n % 2 != 0) {
            ans = ((ans) % m * (xx) % m) % m;
        }
        xx = ((xx) % m * (xx) % m) % m;
        n = n >> 1;
    }
    return (int)(ans % m);
}

// leetcode code
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn & 1) {
                ans *= x;
                nn -= 1;
            } else {
                x *= x;
                nn = nn / 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};