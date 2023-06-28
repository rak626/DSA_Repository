class Solution {
    // 2. run bfs and find out how many time needed to rot all the oranges

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // vector<vector<int>> vis(n, vector<int>(m, 0));

        int vis[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int tm = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if (dr >= 0 and dr < n and dc >= 0 and dc < m and
                    vis[dr][dc] == 0 and grid[dr][dc] == 1) {
                    q.push({{dr, dc}, t + 1});
                    vis[dr][dc] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 and vis[i][j] != 2) return -1;
            }
        }
        return tm;
    }
};