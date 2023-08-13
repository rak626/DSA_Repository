class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create adj list
        vector<pair<int,long long>> adj[n];
        
        for(int i = 0 ; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        //create distance and ways array and initialize it
        vector<long long> dist(n, LONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        // create priotiy queue
        priority_queue<pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        int mod = (int) 1e9 + 7;

        while(pq.size()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edgeWeight = it.second;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dis + edgeWeight , adjNode});
                    ways[adjNode] = ways[node];
                } 
                else if(dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
        
    }
};