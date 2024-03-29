class Solution {
public:
    // direction arrays
    int di[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    // dfs but run one each eight direction
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        for (int i = 0; i < 8; i++) {
            int cal_row = row + di[i];
            int cal_col = col + dj[i];

            // checking all condition before calling dfs
            if (cal_row >= 0 && cal_row < grid.size() && cal_col >= 0 &&
                cal_col < grid[0].size() && !vis[cal_row][cal_col] &&
                grid[cal_row][cal_col] == '1') {
                vis[cal_row][cal_col] = 1;
                dfs(cal_row, cal_col, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();

        // create visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        // run dfs on connected components on adjacency matrix
        // count how many connected components are there
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    vis[i][j] = 1;
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(n^2);
// Space Complexity : O(n^2);
