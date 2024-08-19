class Solution {
    void solve(int row, int col, vector<vector<int>>& m, int n, string move, int delrow[], int delcol[], vector<string>& ans, vector<vector<int>>& vis) {
        if (row == n - 1 and col == n - 1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and nrow < n and ncol < n and ncol >= 0 and !vis[nrow][ncol] and m[nrow][ncol] == 1) {
                vis[row][col] = 1;
                solve(nrow, ncol, m, n, move + dir[i], delrow, delcol, ans, vis);
                vis[row][col] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1) solve(0, 0, m, n, "", delrow, delcol, ans, vis);
        return ans;
    }
};
