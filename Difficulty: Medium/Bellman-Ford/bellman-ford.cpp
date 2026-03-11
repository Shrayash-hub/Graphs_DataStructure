// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src] = 0;
        //  relax all edges V-1 times
        // because the longest shortest path can have at most V-1 edges
        for(int i=1; i<=V-1; i++){
            for(auto &edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        //  check for negative weight cycle
        // if we can still relax an edge → negative cycle exists
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
