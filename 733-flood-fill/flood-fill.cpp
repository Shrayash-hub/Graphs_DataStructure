class Solution {
public:
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
        dfs(grid, i+1, j, oldColor, newColor);
        dfs(grid, i-1, j, oldColor, newColor);
        dfs(grid, i, j+1, oldColor, newColor);
        dfs(grid, i, j-1, oldColor, newColor);
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