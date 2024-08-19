// dfs solution

class Solution {
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& col) {
        for (auto it : graph[start]) {
            if (col[it] == -1) {
                col[it] = !col[start];
                if (dfs(it, graph, col) == 0) return 0;
            } else if (col[it] == col[start]) {
                return 0;
            }
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                col[i] = 0;
                if (dfs(i, graph, col) == 0) return 0;
            }
        }
        return 1;
    }
};
