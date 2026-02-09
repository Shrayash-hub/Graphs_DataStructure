class Solution {
public:
    vector<vector<char>> board;

    // hashing arrays for storing
    bool rowUsed[9][10] = {false};
    bool colUsed[9][10] = {false};
    bool boxUsed[9][10] = {false};

    // empty cells row clm
    vector<pair<int,int>> emptyCells;

    
    bool solve(int index) {
        // when all empty cells filled
        if (index == emptyCells.size())
            return true;

        int row = emptyCells[index].first;
        int col = emptyCells[index].second;

        int boxIndex = (row / 3) * 3 + (col / 3);

        // trying numbers 1 to 9
        for (int num = 1; num <= 9; num++) {

            if (!rowUsed[row][num] &&
                !colUsed[col][num] &&
                !boxUsed[boxIndex][num]) {

                // placed  number
                board[row][col] = num + '0';
                rowUsed[row][num] = true;
                colUsed[col][num] = true;
                boxUsed[boxIndex][num] = true;

                // recurse for next empty cell
                if (solve(index + 1))
                    return true;

                // backtrack if we got dead end
                board[row][col] = '.';
                rowUsed[row][num] = false;
                colUsed[col][num] = false;
                boxUsed[boxIndex][num] = false;
            }
        }

        return false; // no number worked
    }

    void solveSudoku(vector<vector<char>>& inputBoard) {

        board = inputBoard;

        // intializing tracking arrays and emptyCells
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                } else {
                    int num = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    boxUsed[boxIndex][num] = true;
                }
            }
        }

        solve(0);

        inputBoard = board; // copying solved board back
    }
};
