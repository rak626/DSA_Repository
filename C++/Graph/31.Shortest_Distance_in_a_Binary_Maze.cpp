class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, source});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[source.first][source.second] = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            int dis = top.first;
            auto pos = top.second;
            for (int i = 0; i < 4; i++) {
                int nrow = pos.first + dx[i];
                int ncol = pos.second + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    pq.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        if (dist[destination.first][destination.second] == 1e9) return -1;
        return dist[destination.first][destination.second];
    }
};
