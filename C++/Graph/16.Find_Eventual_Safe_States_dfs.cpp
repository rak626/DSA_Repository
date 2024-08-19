class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, map<int, int>& safeNodes) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (vis[it] == 0) {
                if (dfs(it, graph, vis, pathVis, safeNodes) == 0) return 0;
            } else if (pathVis[it] == 1) {
                return 0;
            }
        }
        safeNodes[node] = 1;
        pathVis[node] = 0;
        return 1;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        map<int, int> safeNodes;
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, vis, pathVis, safeNodes);
            }
        }
        for (auto it : safeNodes) {
            ans.push_back(it.first);
        }
        return ans;
    }
};