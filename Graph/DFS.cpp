class Solution {
    void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
        vis[i] = 1;
        ans.push_back(i);
        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V, 0);
        dfs(0, adj, vis, ans);
        return ans;
    }
};