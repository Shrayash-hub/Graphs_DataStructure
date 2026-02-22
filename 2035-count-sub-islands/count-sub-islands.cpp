class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool dfs(vector<vector<int>>& grid1,
             vector<vector<int>>& grid2,
             int i,int j,int row, int clm){

        // assume this cell is valid sub island cell only if grid1 also has land
        bool isSubIsland = (grid1[i][j] == 1);

        // marking visited in grid2
        grid2[i][j] = 0;

        for(int k=0;k<4;k++){
            int newi = i + dx[k];
            int newj = j + dy[k];

            // check for grid2==1 
            if(newi>=0 && newj>=0 && newi<row && newj<clm && grid2[newi][newj]==1){

                // if any neighbour is not sub island -> whole island is invalid
                if(!dfs(grid1,grid2,newi,newj,row,clm)){
                    isSubIsland = false;
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid2[i][j]==1){

                    // if whole island valid -> increase the count
                    if(dfs(grid1,grid2,i,j,n,m)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};