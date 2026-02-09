class Solution {
public:
    void solve(int col, int n,
               vector<int>& leftRow,
               vector<int>& upperDiag,
               vector<int>& lowerDiag,
               int& count) {

        // when all columns filled
        if (col == n) {
            count++;      // valid solution
            return;
        }

        // try placing queen in every row of this column
        for (int row = 0; row < n; row++) {

            // safety check
            if (leftRow[row] == 0 &&
                upperDiag[row + col] == 0 &&
                lowerDiag[n - 1 + col - row] == 0) {

                // put queen
                leftRow[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[n - 1 + col - row] = 1;

                // Recurse to next column
                solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);

                // backtrack -> removing that queen
                leftRow[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[n - 1 + col - row] = 0;
            }
        }
    }

    int totalNQueens(int n) {

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2*n - 1, 0);
        vector<int> lowerDiag(2*n - 1, 0);

        int count = 0;

        solve(0, n, leftRow, upperDiag, lowerDiag, count);

        return count;
    }
};
