class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 && j != 0) {
                    // there are 2 ways to come in middle cells (up and left)
                    // so we will take minimum one
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                } else if (j == 0 && i > 0) {
                    // only one way to come in these cells -> left side se
                    grid[i][j] += grid[i - 1][j];
                } else if (i == 0 && j > 0) {
                    // same only one way to come these cells -> up se
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};