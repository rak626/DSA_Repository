class Solution {
    bool dfs(int row, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[row] = 1;
        pathVis[row] = 1;
        for(auto it : adj[row]){
            if(vis[it] == 0){
                if(dfs(it, adj, vis, pathVis)) return 1;
            } else if(pathVis[it]  == 1){
                return 1;
            }
        }
        pathVis[row] = 0;
        return 0;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0) ;
        vector<int> pathVis(V, 0);
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0){
                if(dfs(i , adj, vis ,pathVis) == 1) return 1;
            }
        }
        return 0;
    }
};