class Solution {
  public:
    void dfs(vector<int> adj[], int node, vector<int> &vis){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                dfs(adj,it,vis);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        int count = 0;
        vector<int> adj[V];
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        
        for(int i = 0; i<V; i++){
            if(vis[i]==0){
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;
    }
};