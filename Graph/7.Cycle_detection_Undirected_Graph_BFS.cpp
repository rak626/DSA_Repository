#include <bits/stdc++.h>
bool detectCycle(int src, vector<int> adj[], bool vis[]) {
    // initialize vis and queue for starting bfs
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    // run bfs
    while (q.size()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjNode : adj[node]) {
            if (vis[adjNode] == 0) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            // if adjNode is not parent( becasue we can traverse parent from cur node as well)
            else if (parent != adjNode) {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Write your code here.
    if (m == 0) return "No";

    // create adj list
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    // create visited array
    bool vis[n + 1] = {0};
    bool ans = 0;
    // run bfs on connected Components
    for (int i = 1; i < n + 1; i++) {
        if (vis[i] != 1) {
            ans = detectCycle(i, adj, vis);
            // if anytime we find a cycle then just return true
            if (ans) return "Yes";
        }
    }
    return "No";
}

/*
T.C. -> undirected graph : O(V + 2 * E);
S.C. -> O(2 * N), including adjacency list.
*/