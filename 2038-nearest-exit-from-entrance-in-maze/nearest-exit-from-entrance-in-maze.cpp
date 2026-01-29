class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        grid[entrance[0]][entrance[1]] = '+';

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int steps=0;
        while (!q.empty()) {
            // using bfs
            int size = q.size();
            steps++;
            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                int dist = grid[i][j];

                // checking all the adjacent side of orange
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                        grid[ni][nj] == '.') {
                        if (ni == 0 || nj == 0 || ni == n - 1 || nj == m - 1) {
                            return steps;;
                        }
                        grid[ni][nj] = '+';
                        q.push({ni, nj});
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};