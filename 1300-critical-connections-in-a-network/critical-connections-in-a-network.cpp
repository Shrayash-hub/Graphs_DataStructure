class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, int tim[], int low[],
             vector<int> adj[], vector<int> &vis,
             vector<vector<int>>& bridges) {

        vis[node] = 1;

        // assign discovery time and initialize low
        tim[node] = low[node] = timer++;

        for (auto nbr : adj[node]) {

            if (nbr == parent) continue; // ignore parent

            if (!vis[nbr]) {
                // exploring deeper
                dfs(nbr, node, tim, low, adj, vis, bridges);

                // updating low using child
                low[node] = min(low[node], low[nbr]);

                // checking bridge condition
                if (tim[node] < low[nbr]) {
                    bridges.push_back({node, nbr});
                }
            }
            else {
                // back edge -> update using discovery time
                low[node] = min(low[node], tim[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<int> adj[n];

        for (auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tim[n], low[n];
        vector<vector<int>> bridges;

        // handling disconnected graph
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, tim, low, adj, vis, bridges);
            }
        }

        return bridges;
    }
};