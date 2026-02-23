class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 1)
            return true;

        grid[i][j] = 1; // Mark as visited

        bool isClosed = true;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size()) {
                // Call DFS first, Then combine the result.
                bool res = dfs(grid, ni, nj);
                isClosed = isClosed && res;
            } else {
                // Boundary touched
                isClosed = false;
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 1; i < n - 1; i++) {

            for (int j = 1; j < m - 1; j++) {

                if (grid[i][j] == 0) {

                    if (dfs(grid, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};