class Solution {
public:
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // initial setup of vis array and queue
        int vis[n] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        // run bfs
        while (q.size()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

/*
T.C. -> undirected graph : O(V) + O(2 * E);
     -> directed graph :  O(V) + O(E);
S.C. -> O(3 * N), including adjacency list.
 */