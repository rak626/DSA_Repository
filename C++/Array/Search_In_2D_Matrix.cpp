/*===========================
Search In A 2D Matrix
===========================*/

// optimal approach for gfg and better approach for leetcode
#include <bits/stdc++.h>

#include <vector>

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target) {
    int i = 0, j = n - 1;
    while (i < m and j >= 0) {
        if (mat[i][j] == target) return 1;
        if (mat[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return 0;
}

// optimal approach for leetcode

#include <bits/stdc++.h>

#include <vector>

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target) {
    if (!mat.size()) return false;
    int l = 0, h = (m * n) - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        int cur = mat[mid / n][mid % n];
        if (cur == target) return 1;
        if (target < cur) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}