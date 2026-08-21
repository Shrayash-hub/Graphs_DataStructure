class Solution {
	public:
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
		visited[i][j] = 1;
		
		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k];
			int nj = j + dy[k];
			
			if (ni < visited.size() && nj < visited[0].size() && ni >= 0 && nj >= 0 && grid[ni][nj] == 1
			 && visited[ni][nj] == false) {
				dfs(ni, nj, visited, grid);
			}
		}
	}
	int cntOnes(vector<vector<int>> & grid) {
		// code here
		int n = grid.size();
		int m = grid[0].size();
		
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		
		// lets look for the boundary 1's
		
		// first looking for the first and last row 1's
		for (auto i: {0, n - 1}) {
			for (int j = 0; j < m - 1; j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					dfs(i, j, visited, grid);
				}
			}
		}
		
		// then looking for the first and last clm 1's
		for (int i = 0 ; i < n - 1; i++) {
			for (auto j: {0, m - 1}) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					dfs(i, j, visited, grid);
				}
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					cnt++;
				}
			}
		}
		return cnt;
		
	}
};
