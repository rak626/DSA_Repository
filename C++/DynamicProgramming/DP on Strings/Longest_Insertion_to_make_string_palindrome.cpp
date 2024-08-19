// Minimum insertions to make a string palindrome

#include <bits/stdc++.h>
int minInsertion(string &str) {
    // Write your code here.
    int n = str.size();
    int m = n;
    string str2 = str;
    reverse(str2.begin(), str2.end());
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 0; j <= m; j++) prev[j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i - 1] == str2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
            } else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return n - prev[m];
}