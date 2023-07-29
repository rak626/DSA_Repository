class Solution {
    void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis,
             stack<int>& st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) dfs(v, adj, vis, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        // create the graph
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // topo sort in dfs
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> dis(N);
        for (int i = 0; i < N; i++) {
            dis[i] = 1e9;
        }
        // current question src is 0,
        int src = 0;

        dis[src] = 0;
        while (st.size()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[v]) {
                    dis[v] = dis[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dis[i] == 1e9) dis[i] = -1;
        }
        return dis;
    }
};