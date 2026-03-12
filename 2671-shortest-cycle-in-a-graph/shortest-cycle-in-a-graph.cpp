class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // lets build adj matrix from the given connected nodes
        vector<int> adj[n];

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // now we will use cycle detection algo in graph , where we mark visited
        // to the nodes while traversing(BFS) and if we find that , any node is
        // already visited and its parent is not u (as we are traversing u->v)
        // -> that show there is a cycle in the graph

        // but we need to run bfs from every node , as graph can have multiple
        // connected components
        int ans = INT_MAX;

        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1); // to save the distance from the start node
            vector<int> parent(n, -1); // to save the parent of a node

            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // exploring all the nei
                for (auto& nei : adj[node]) {

                    // if nei is not visited
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1; // node distance from start + 1
                        parent[nei] = node; // node is going to be parent
                        q.push(nei);
                    }
                    // nei is visited
                    // check is nei is not the parent of the node
                    else if (parent[node] != nei) {
                        // distance of nei from start + distance of node from
                        // start
                        // + distance between node and nei(1)
                        int cycleLength = dist[nei] + dist[node] + 1;
                        ans = min(ans, cycleLength);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};