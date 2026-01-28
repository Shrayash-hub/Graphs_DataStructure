class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int row, int clm) {
        // if water, no perimeter
        if (grid[i][j] == 0) {
            return 0;
        }

        int peri = 4;

        // up
        if (i > 0 && grid[i-1][j] == 1) peri--;

        // left
        if (j > 0 && grid[i][j-1] == 1) peri--;

        // right
        if (j < clm-1 && grid[i][j+1] == 1) peri--;

    // down
        if (i < row-1 && grid[i+1][j] == 1) peri--;

        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int finalPeri = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int peri = helper(grid,i,j,grid.size(),grid[0].size());
                finalPeri+=peri;
            }
        }
        return finalPeri;
    }
};