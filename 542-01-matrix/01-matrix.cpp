class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int other = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                } else {
                    grid[i][j]=-1;
                    other++;
                }
            }
        }
        int x = 0;
        while (!q.empty() && other > 0) {
            // using bfs
            x++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                // checking all the adjacent side of orange
                if (i + 1 < n && grid[i + 1][j] == -1) {
                    grid[i + 1][j] = x;
                    q.push({i + 1, j});
                    other--;
                }
                if (j + 1 < m && grid[i][j + 1] == -1) {
                    grid[i][j + 1] = x;
                    q.push({i, j + 1});
                    other--;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == -1) {
                    grid[i - 1][j] = x;
                    q.push({i - 1, j});
                    other--;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == -1) {
                    grid[i][j - 1] = x;
                    q.push({i, j - 1});
                    other--;
                }
                q.pop();
            }
        }
        return grid;
    }
};