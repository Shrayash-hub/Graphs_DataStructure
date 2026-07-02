class Solution {
	public:
	void dfs(vector<int> adj[], vector<bool>& visited, int node) {
		visited[node] = true;
		
		for (auto it: adj[node]) {
			if (visited[it] == false)
				dfs(adj, visited, it);
		}
	}
	int countConnected(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> adj[V];
		for (auto it: edges) {
			int u = it[0];
			int v = it[1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		int count = 0;
		for (int i = 0; i < V; i++) {
			if (visited[i] != true) {
				count++;
				dfs(adj, visited, i);
			}
		}
		return count;
	}
};
