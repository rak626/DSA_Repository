// K Max Sum Combinations

#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minha, minhb;

    for (int i = 0; i < n; i++) {
        minha.push(a[i]);
        if (minha.size() > k) minha.pop();
        minhb.push(b[i]);
        if (minhb.size() > k) minhb.pop();
    }

    vector<int> ans;
    while (k--) {
        ans.push_back(minha.top() + minhb.top());
        minha.pop();
        minhb.pop();
    }
    return ans;
}