class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<vector<int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (q.size()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > K) continue;
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeCost = it[1];
                if (cost + edgeCost < dist[adjNode] && stops <= K) {
                    dist[adjNode] = cost + edgeCost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
