class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i,
             int j) {
        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];

            if (newi >= 0 && newj >= 0 && newi < board.size() &&
                newj < board[0].size() && !visited[newi][newj] &&
                board[newi][newj] == 'O') {
                dfs(board, visited, newi, newj);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // top and bottom row
        int i = 0;
        while (i < n) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    dfs(board, visited, i, j);
                }
            }

            if (i == n - 1)
                break;
            i += (n - 1);
        }

        // left and right column
        int j = 0;
        while (j < m) {
            for (int i = 0; i < n; i++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    dfs(board, visited, i, j);
                }
            }

            if (j == m - 1)
                break;
            j += (m - 1);
        }

        // convert remaining O to X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
