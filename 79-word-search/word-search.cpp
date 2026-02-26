class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool dfs(int index, vector<vector<char>>& board, string word, int i,
             int j) {
        if (board[i][j] !=word[index]) {
            return false;
        }
        if (index == word.size()-1) {
            return true;
        }
        char curr = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k <= 3; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if (newi >= 0 && newj >= 0 && newi < board.size() && newj < board[0].size() &&
                board[newi][newj] != '#') {
                if (dfs(index + 1, board, word, newi, newj)) {
                    //board[i][j] = curr;
                    return true;
                }
            }
        }
        board[i][j] = curr;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]==word[0]){
                    if (dfs(0, board, word, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};