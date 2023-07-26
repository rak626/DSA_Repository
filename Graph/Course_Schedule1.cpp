class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph
        int n = numCourses;
        vector<int> adj[n];
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (q.size()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (cnt == n) return 1;
        return 0;
    }
};