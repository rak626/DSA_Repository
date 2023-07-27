class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++) {
            string cur = dict[i], next = dict[i + 1];
            for (int j = 0; j < min(cur.size(), next.size()); j++) {
                if (cur[j] != next[j]) {
                    adj[cur[j] - 'a'].push_back(next[j] - 'a');
                    break;
                }
            }
        }

        vector<int> indegree(K, 0);

        for (int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // run topo sort
        string ans;

        while (q.size()) {
            int node = q.front();
            q.pop();
            ans.push_back('a' + node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};