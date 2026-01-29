class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        while (!q.empty()) {
            // using bfs
            int size = q.size();

            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                int dist = grid[i][j];

                // reached destination
                if (i == n - 1 && j == n - 1) {
                    return dist;
                }
                // checking all the adjacent side of orange
                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    

                    if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                        grid[ni][nj] == 0) {
                        grid[ni][nj] = 1+ dist;
                        q.push({ni, nj});
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};