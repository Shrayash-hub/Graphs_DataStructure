class Solution {
	public:
	bool dfs(int curr, int parent, vector<int> adj[], vector<bool> &visited) {
		visited[curr] = true;
		
		for (auto it: adj[curr]) {
		    if (it == parent) continue;
			if (visited[it] == true && it != parent) {
				return true;
			}
			if(dfs(it, curr, adj, visited)) return true;
		}
		return false;
	}
	
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		vector<int> adj[V+1];
		
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				if (dfs(i, -1, adj, visited)) {
					return true;
				}
			}
		}
		return false;
	}
};
