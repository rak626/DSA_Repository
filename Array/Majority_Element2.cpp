/*===================================
Majority Elements(>N/3 times)
===================================*/

#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr) {
    int n = arr.size();
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for (auto ele : arr) {
        if (ele == num1)
            c1++;
        else if (ele == num2)
            c2++;
        else if (c1 == 0)
            num1 = ele, c1 = 1;
        else if (c2 == 0)
            num2 = ele, c2 = 1;
        else
            c1--, c2--;
    }
    c1 = c2 = 0;
    for (auto ele : arr) {
        if (ele == num1) c1++;
        if (ele == num2) c2++;
    }
    vector<int> ans;
    if (c1 > n / 3) {
        ans.push_back(num1);
    }
    if (c2 > n / 3) {
        ans.push_back(num2);
    }
    return ans;
}