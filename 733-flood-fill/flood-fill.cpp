class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int i,int j,int oldColor,int newColor){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
    
        // If current cell is not the old color, return
        if (grid[i][j] != oldColor) {
            return;
        }
    
        // Paint with new color
        grid[i][j] = newColor;

        // Recursively fill in all 4 directions
        for(int k=0;k<4;k++){
            int newi = i + dx[k];
            int newj = j + dy[k];
            dfs(grid,newi,newj,oldColor,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty()) return image;
    
        int oldColor = image[sr][sc];
    
        // If old and new colors are same, no need to fill
        if(oldColor == color) return image;
    
        dfs(image, sr, sc, oldColor, color);
    
        return image;
    }
};