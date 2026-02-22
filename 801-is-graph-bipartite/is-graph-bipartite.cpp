class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node,
             int nodeColor) {
        color[node] = nodeColor;
        for (auto it : graph[node]) {
            // not visited
            if (color[it] == -1) {
                if (dfs(graph, color, it, !nodeColor) == false)
                    return false;
            }
            // visited
            else {
                if (color[it] == nodeColor) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // a bipartite graph is a graph , in which there is no adjacent node with the same color assigned (if we are assigning one of 2 color to each node(0 or 1))

        // a graph with odd cycle can only be a non bipartite graph , baki sab bipartite hongey
        int V = graph.size();
        // visited array
        vector<int> color(V, -1);
        int col = 0;
        // call for every component
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(graph, color, i, col) == false)
                    return false;
            }
        }
        return true;
    }
};