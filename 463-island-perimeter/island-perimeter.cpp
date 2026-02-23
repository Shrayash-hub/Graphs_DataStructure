class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>>& grid, int i, int j) {

        // out of bounds -> contributes 1
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 1;

        // water -> contributes 1
        if (grid[i][j] == 0)
            return 1;

        // already visited land -> contributes 0
        if (grid[i][j] == -1)
            return 0;

        // mark visited
        grid[i][j] = -1;

        int peri = 0;

        for (int k = 0; k < 4; k++) {
            peri += dfs(grid, i + dx[k], j + dy[k]);
        }

        return peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};