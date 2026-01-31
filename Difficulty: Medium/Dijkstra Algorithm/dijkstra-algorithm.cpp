class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Step 1: Build adjacency list
        // adj[u] = { {v, weight}, ... }
        vector<vector<pair<int,int>>> adj(V);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        // Step 2: Min-heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        // Step 3: Dijkstra
        while(!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entry
            if(currDist > dist[node])
                continue;

            // Explore neighbours
            for(auto &edge : adj[node]) {
                int nbr = edge.first;
                int wt  = edge.second;

                if(dist[node] != INT_MAX && dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        return dist;
    }
};