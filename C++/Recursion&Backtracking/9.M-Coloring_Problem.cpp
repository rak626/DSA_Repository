class Solution {
    bool isSafe(int node, int color[], bool graph[][], int n, int col) {
        for (int i = 0; i < n; i++) {
            if (i != node && graph[i][node] == 1 && color[i] == col) return 0;
        }
        return 1;
    }

    bool solve(int node, int color[], int m, int n, bool graph[][]) {
        if (node == n) return 1;

        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, graph, n, i)) {
                color[node] = i;
                if (solve(node + 1, color, m, n, graph)) return 1;
                color[node] = 0;
            }
        }
        return 0;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[N] = {0};

        if (solve(0, color, m, n, graph)) return 1;
        return 0;
    }
};
