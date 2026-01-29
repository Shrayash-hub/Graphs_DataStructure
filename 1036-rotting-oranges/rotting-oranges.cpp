class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // take the count of rotten oranges
                if (grid[i][j] == 2) {
                    q.push({i, j});
                // at the same time take the count of fresh oranges
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int time = 0;
        // if there are no rotten oranges , then there is no chance of other to be rotten
        while (!q.empty() && fresh > 0) {
            // using bfs
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                // checking all the adjacent side of orange
                if (i + 1 < n && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                    fresh--;
                }
                if (j + 1 < m && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                    fresh--;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                    fresh--;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                    fresh--;
                }
                q.pop();
            }
            // at each iteration time is going to increse by 1 second
            time++;
        }
        // if there are fresh oranges left in grid
        if (fresh > 0)
            return -1;

        return time;
    }
};