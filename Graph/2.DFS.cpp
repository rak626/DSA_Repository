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
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        // create vis array
        vector<int> vis(V, 0);
        dfs(0, adj, vis, ans);
        return ans;
    }
};

/*
T.C. -> undirected graph : O(V) + O(2 * E);
     -> directed graph :  O(V) + O(E);
S.C. -> O(3 * N), including adjacency list.
 */