class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        for (int j = 0; j < col; j++)
            if (board[row][j] == 'Q') return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(int col, int n,
               vector<string>& board,
               vector<vector<string>>& ans) {

        // base case all columns filled
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // try all rows in current column
        for (int row = 0; row < n; row++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';      // Put queen
                solve(col + 1, n, board, ans);
                board[row][col] = '.';      // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // empty board
        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);
        return ans;
    }
};
