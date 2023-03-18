class Solution {
    void dfs(int start, vector<vector<int>> &adj, vector<int> &vis) {
        vis[start] = 1;
        for (auto it : adj[start]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> nums, int V) {
        // code here
        int cnt = 0;
        vector<int> vis(V, 0);

        // create adj list

        vector<vector<int>> adj(V);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (i != j && nums[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};