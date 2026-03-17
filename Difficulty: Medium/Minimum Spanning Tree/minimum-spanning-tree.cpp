class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // making adj list
        vector<pair<int,int>> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        // using Prim's algo
        vector<int> vis(V,0);
        
        // min heap
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq; // {weight,{node,parent}}
        
        pq.push({0,{0,-1}});
        
        vector<pair<int,int>> mst;
        int sum = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int wt = temp.first;
            int node = temp.second.first;
            int parent = temp.second.second;
            
            if(vis[node]!=1){
                vis[node] = 1;
                sum+=wt;
                mst.push_back({node,parent});
                
                for(auto &nei: adj[node]){
                    int next = nei.first;
                    int wtNext = nei.second;
                    
                    if(vis[next]!=1){
                        pq.push({wtNext,{next,node}});
                    }
                }
            }
        }
        return sum;
    }
};