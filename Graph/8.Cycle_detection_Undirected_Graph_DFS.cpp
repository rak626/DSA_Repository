bool dectectCycleDfs(int src, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[src] = true;

    for (auto adjNode : adj[src]) {
        if (!vis[adjNode]) {
            vis[adjNode] = true;
            if (dectectCycleDfs(adjNode, src, adj, vis)) return true;
        } else if (parent != adjNode) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> vis(n + 1);

    for (int i = 1; i < n; i++) {
        if (!vis[i]) {
            if (dectectCycleDfs(i, -1, adj, vis)) return "Yes";
        }
    }
    return "No";
}
/*
T.C. -> undirected graph : O(V + 2 * E);
S.C. -> O(2 * N), including adjacency list.
*/

/*
To summarize:
- Time Complexity: O(2 * ( V + E))
- Space Complexity: O(V + E)

Time Complexity:
1. Building the adjacency list `adj` takes O(m) time, where m is the number of edges. We iterate through the `edges` vector once to populate the adjacency list.
2. The loop from 1 to n iterates n-1 times, where n is the number of nodes. In each iteration, it checks if the node is visited or not.
3. The `detectCycleDfs` function is called for each unvisited node, and it performs a depth-first search (DFS) on the graph. The time complexity of the DFS is determined by the number of edges in the graph. In the worst case, each edge is traversed exactly once.
4. The time complexity of DFS is O(V + E), where V is the number of vertices (nodes) and E is the number of edges. Since we are using an adjacency list representation, the time complexity for accessing the neighbors of a node is O(1) on average.
5. Overall, the time complexity of the `cycleDetection` function is O(m + n + V + E).

Space Complexity:
1. The `adj` vector, which represents the adjacency list, requires O(m) space to store all the edges.
2. The `vis` vector is used to keep track of visited nodes and requires O(n) space to store the visited status of each node.
3. The depth of the recursive call stack in the `detectCycleDfs` function can be at most O(n) in the worst case, where n is the number of nodes.
4. Other variables used in the function take constant space and do not depend on the size of the graph.

So, the total space complexity is O(m + n).


Both the time and space complexities are dependent on the number of nodes (n) and edges (m) in the graph. The solution is efficient for relatively small graphs but may face performance issues for large graphs with a high number of nodes and edges.
*/