class Solution {
public:
    int n, m;

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        // memoization check
        if (dp[i][j] != 0) return dp[i][j];

        int ans = 1;

        // DOWN
        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
            ans = max(ans, 1 + dfs(i + 1, j, matrix, dp));
        }

        // UP
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            ans = max(ans, 1 + dfs(i - 1, j, matrix, dp));
        }

        // RIGHT
        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
            ans = max(ans, 1 + dfs(i, j + 1, matrix, dp));
        }

        // LEFT
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            ans = max(ans, 1 + dfs(i, j - 1, matrix, dp));
        }

        return dp[i][j] = ans; // store result
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, dfs(i, j, matrix, dp));
            }
        }

        return result;
    }
};