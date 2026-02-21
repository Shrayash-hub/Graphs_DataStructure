class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& board, vector<vector<int>>& visited, int i,
             int j) {
        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];

            if (newi >= 0 && newj >= 0 && newi < board.size() &&
                newj < board[0].size() && !visited[newi][newj] &&
                board[newi][newj] == 1) {
                dfs(board, visited, newi, newj);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // top and bottom row
        int i = 0;
        while (i < n) {
            for (int j = 0; j < m; j++) {
                // if board have 1 and its still not visited call bfs for that
                if (board[i][j] == 1 && !visited[i][j]) {
                    dfs(board, visited, i, j);
                }
            }

            if (i == n - 1)
                break;
            i += (n - 1);
        }

        // left and right column
        i = 0;
        while (i < m) {
            for (int j = 0; j < n; j++) {
                if (board[j][i] == 1 && !visited[j][i]) {
                    dfs(board, visited, j, i);
                }
            }

            if (i == m - 1)
                break;
            i += (m - 1);
        }

        int count = 0;

        // convert the number of 1's that are not visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && visited[i][j] != 1) {
                    count++;
                }
            }
        }
        return count;
    }
};