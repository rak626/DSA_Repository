class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        // intializing queue and vis matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if nearest '0' needed we load 0,
                // if nearest '1' needed we load '1' into queue
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (q.size()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curDis = q.front().second;
            q.pop();

            dis[row][col] = curDis;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, curDis + 1});
                }
            }
        }
        return dis;
    }
};

// time complexity : O(n * m)
// space complexity : O(n * m)