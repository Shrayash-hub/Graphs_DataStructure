class Solution {
  private:
    int timer = 1;

    void dfs(int node, int parent, int tin[], int low[],
             vector<int> adj[], vector<int> &vis,
             vector<int>& mark) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int child = 0;

        for (auto nbr : adj[node]) {

            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(nbr, node, tin, low, adj, vis, mark);

                low[node] = min(low[node], low[nbr]);

                // articulation condition
                if (low[nbr] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            }
            else {
                low[node] = min(low[node], tin[nbr]);
            }
        }

        // root case
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {

        vector<int> vis(n, 0);
        int tin[n], low[n];
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, adj, vis, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0) return {-1};

        return ans;
    }
};