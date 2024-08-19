// typedef pair<int,int> pii;
class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (pq.size()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int v = it[0];
                int wt = it[1];
                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dis + wt, v});
                }
            }
        }
        return dist;
    }
};

// time complexity :-   E log V
