class Solution {
public:
    // exactly same question as maxArea of island
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
        }
        int count = grid[i][j];

        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            count += dfs(grid, ni, nj);
        }
        return count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxFish = INT_MIN;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int temp = dfs(grid, i, j);
                    if (temp > maxFish) {
                        maxFish = temp;
                        flag = true;
                    }
                }
            }
        }
        return flag == true ? maxFish : 0;
    }
};