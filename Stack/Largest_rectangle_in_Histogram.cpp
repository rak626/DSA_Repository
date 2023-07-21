// Largest rectangle in a histogram

// using 2 pass
#include <bits/stdc++.h>
int largestRectangle(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() and heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int area = (right[i] - left[i] + 1) * heights[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// using single pass

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() and (i == n or heights[i] < heights[st.top()])) {
                int curHeight = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, curHeight * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
