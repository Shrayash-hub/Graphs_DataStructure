class Solution {
public:
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                         {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int countMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;

        for (auto &dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (nr >= 0 && nr < board.size() && nc >= 0 &&
                nc < board[0].size()) {
                if (board[nr][nc] == 'M')
                    count++;
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return;

        if (board[r][c] != 'E')
            return;

        int mines = countMines(board, r, c);

        if (mines > 0) {
            board[r][c] = mines + '0';
            return;
        }

        board[r][c] = 'B';

        for (auto& dir : directions) {
            dfs(board, r + dir.first, c + dir.second);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {

        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);

        return board;
    }
};
