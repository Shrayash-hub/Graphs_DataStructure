class Solution {
	public:
	void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &curr, int node) {
		visited[node] = true;
		curr.push_back(node);
		
		for (auto it: adj[node]) {
			if (!visited[it]) {
				dfs(adj, visited, curr, it);
			}
		}
	}
	int findNumberOfGoodComponent(int e, int V, vector<vector<int>> &edges) {
		// code here
		int n = edges.size();
		
		// lets make adj list
		// as thier is 1 based indexing , make adj matrix of v+1 size
		vector<vector<int>> adj(V+1);
		
		for (auto it: edges) {
			int u = it[0];
			int v = it[1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		int ans = 0;
		vector<bool> visited(V+1, false);
		for (int node = 1; node <= V; node++) {
			if (!visited[node]) {
			    // find the nodes in the current components
				vector<int> curr;
				dfs(adj, visited, curr, node);
				
				int nodes = curr.size();
				
				// edge count : we will get from the adj matrix 
				int edgeCount = 0;
				
				for (auto it: curr) {
					edgeCount += adj[it].size();
				}
				
				// as graph is undirected
				edgeCount = edgeCount/2;
				
				// condition to remember for the good components
				if (edgeCount == (nodes * (nodes - 1)) / 2) {
					ans++;
				}
			}
		}
		
		return ans;
	}
};
