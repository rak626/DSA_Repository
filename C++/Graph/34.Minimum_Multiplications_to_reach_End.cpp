class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;

        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        queue<pair<int, int>> q;
        q.push({start, 0});

        while (q.size()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (node == end) return steps;

            for (auto it : arr) {
                int num = (node * it) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};