class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int row,int clm){
        if(i<0 || j<0 || i>=row || j>=clm){
            return 0;
        }
        
        if (grid[i][j] == 0) {
            return 0;
        }

        // mark visited
        grid[i][j] = 0;
        int area =1;
        area += dfs(grid,i+1,j,row,clm);
        area += dfs(grid,i-1,j,row,clm);
        area += dfs(grid,i,j+1,row,clm);
        area += dfs(grid,i,j-1,row,clm);
        
        
        
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int maxArea = 0;
        int row = grid.size();
        int clm = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                  int area = dfs(grid,i,j,row,clm) ;
                  maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};