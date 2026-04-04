class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        vector<vector<int>> dp(row, vector<int>(row, 0));

        // base cases -> as last se start kr rhey h so -> end last row k kisi
        // bhi clm pr ho skta h
        for (int j = 0; j < row; j++) {
            dp[row - 1][j] = triangle[row - 1][j];
        }

        // we are filling rows from the last
        for (int i = row - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // we can either move downward or diaginal
                int down = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,dg);
            }
        }
        return dp[0][0];
    }
};