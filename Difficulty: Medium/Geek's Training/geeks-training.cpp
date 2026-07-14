class Solution {
	public:
	int solve(vector<vector<int>> &mat, int last, int row,
	vector<vector<int>> &dp) {
		
		if (row == mat.size())
			return 0;
		
		if (dp[row][last + 1] != -1)
			return dp[row][last + 1];
		
		int ans = INT_MIN;
		
		for (int i = 0; i < mat[0].size(); i++) {
			if (i != last) {
				ans = max(ans,
				mat[row][i] + solve(mat, i, row + 1, dp));
			}
		}
		
		return dp[row][last + 1] = ans;
	}
	
	int maximumPoints(vector<vector<int>> &mat) {
		int n = mat.size();
		vector<vector<int>> dp(n, vector<int>(4, -1));
		return solve(mat, -1, 0, dp);
	}
};
