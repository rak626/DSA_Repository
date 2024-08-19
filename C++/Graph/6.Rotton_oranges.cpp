class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // vector<vector<int>> vis(n, vector<int>(m, 0));

        int vis[n][m];

        // load all rot position into the queue
        // and mark them into visited array
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
        // run bfs
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
        // after completing bfs, check is there any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 and vis[i][j] != 2) return -1;
            }
        }
        return tm;
    }
};

/*
To summarize:
- Time Complexity: O(n * m)
- Space Complexity: O(n * m)


Time Complexity:
1. Initializing the `vis` array takes O(n * m) time, where n is the number of rows and m is the number of columns in the grid.
2. The loop to find the initial rotten oranges takes O(n * m) time as well, since we iterate through the entire grid once.
3. The BFS (Breadth-First Search) traversal of the grid takes O(n * m) time. In the worst case, all cells might be pushed into the queue.
4. During the BFS, for each cell, we check its neighbors in all four directions. Since there are at most four neighbors for each cell, the neighbor check takes constant time for each cell.
5. Overall, the BFS traversal takes O(n * m) time.

So, the total time complexity is O(n * m).

Space Complexity:
1. The `vis` array is used to keep track of visited cells and takes O(n * m) space since it has the same dimensions as the grid.
2. The queue `q` can store at most all the cells in the grid in the worst case, which would be O(n * m) space.
3. The direction arrays `dx` and `dy` each have a constant size of 4, so they take O(1) space.
4. There are some additional integer variables used for temporary calculations, but they occupy constant space and do not depend on the size of the grid.

So, the total space complexity is O(n * m).


Both the time and space complexities are linear in terms of the number of rows and columns in the grid, making the solution efficient for relatively small grids.
*/