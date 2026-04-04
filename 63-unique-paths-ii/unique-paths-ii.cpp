class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

         // dp state is going to save the number of ways we can reach to this cell -> as multple rasto se hm is cell pr phoch sktey h
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // base case -> as first cell pr aney k 1 way h only
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // similar to unique paths 1 , just jha pr obstacle hoga , vha pr phochney k ways zero ho jayenge , and vhi future me regulate ho jayega , ki obstacle valey path se aney k ways zero h
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) continue;
                int up = 0, left = 0; // we can come in a cell from the upper direction or the side left direction

                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                // add the number ways from both the directions
                dp[i][j] = up + left;
            }
        }

        return dp[n-1][m-1];
    }
};