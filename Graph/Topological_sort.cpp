class Solution
{
    void dfs(int node, vector<int> adj[], int vis[], stack<int>& st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);
        }
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    int vis[V] = {0};
	    
	    stack<int> st;
	    
	    for(int i = 0 ; i < V ; i++){
	        if(!vis[i]) dfs(i, adj, vis, st);
	    }
	    
	    while(st.size()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};