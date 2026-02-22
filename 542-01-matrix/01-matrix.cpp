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
                    grid[i][j] = -1;
                    other++;
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            // using bfs
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                // checking all the adjacent side of cell
                for (int k = 0; k < 4; k++) {
                    int newi = i + dx[k];
                    int newj = j + dy[k];

                    if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
                        grid[newi][newj] == -1) {

                        grid[newi][newj] = grid[i][j] + 1;
                        q.push({newi, newj});
                        
                    }
                }
                q.pop();
            }
        }
        return grid;
    }
};