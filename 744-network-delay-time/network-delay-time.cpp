class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
        vector<vector<pair<int, int>>> adj(V+1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Min-heap (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(V+1, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        // Step 3: Dijkstra
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entry
            if (currDist > dist[node])
                continue;

            // Explore neighbours
            for (auto& edge : adj[node]) {
                int nbr = edge.first;
                int wt = edge.second;

                if (dist[node] != INT_MAX && dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= V; i++) {
            if(dist[i] == INT_MAX)
                return -1;   // unreachable node
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};