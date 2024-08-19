class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];
            adj[u].push_back({v, edgeWeight});
            adj[v].push_back({u, edgeWeight});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        vector<int> dist(n + 1, 1e9), parent(n + 1);
        dist[1] = 0;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        while (pq.size()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dist[n] == 1e9) return {-1};
        vector<int> ans;
        int cur = n;
        while (parent[cur] != cur) {
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(cur);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};