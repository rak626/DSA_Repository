class Solution {
    // simple dfs
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
        int cnt = 0;

        // create adj list and visited array
        vector<vector<int>> adj(V);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (i != j && nums[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(V, 0);

        // run dfs on connected components
        // and count how many connected components are there.
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

// To summarize:
// - Time Complexity: O(V^2)
// - Space Complexity: O(V + E), where E is at most V(V-1)/2.

// Sure, let's analyze the time complexity and space complexity of the provided code.

// **Time Complexity:**

// 1. **Creating Adjacency List:** The code iterates through the given `nums` matrix with dimensions `V x V`, where `V` is the number of vertices. For each vertex, it checks the edges in the row to populate the adjacency list. The worst-case time complexity of this part is O(V^2), where V is the number of vertices.

// 2. **DFS Traversal:** The DFS traversal is performed for each vertex. In the worst case, each vertex might be visited once and each edge might be traversed once. This would lead to a time complexity of O(V + E), where V is the number of vertices and E is the number of edges.

//    However, note that the code is creating an adjacency list based on the given matrix, and the matrix seems to be symmetric (since it's checking `i != j` condition). In an adjacency matrix, this would result in E = V^2 (all possible edges), but since you're using an adjacency list, the maximum number of edges can be V(V-1)/2 (for a fully connected graph). So, the worst-case time complexity for the DFS traversal would be O(V^2).

// Overall, the dominant factor in the time complexity is the DFS traversal, so the overall time complexity of the algorithm is O(V^2).

// **Space Complexity:**

// 1. **Adjacency List:** The space complexity for storing the adjacency list is O(V + E), where V is the number of vertices and E is the number of edges. In the worst case, a fully connected graph would have V(V-1)/2 edges.

// 2. **Visited Array:** The space complexity for the `vis` array is O(V), as it stores a boolean value for each vertex to keep track of whether it has been visited or not.

// 3. **Recursive Call Stack:** The maximum depth of the recursive call stack during DFS traversal is bounded by the number of vertices, i.e., O(V).

// Overall, the space complexity is dominated by the adjacency list and the visited array, making the total space complexity O(V + E), where E can be at most V(V-1)/2.
