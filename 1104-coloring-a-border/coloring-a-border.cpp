class Solution {
public:

    // These arrays help us move in 4 directions
    // up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    /*
    This DFS function explores the connected component starting from given cell.
    
    Goal of DFS is to find border cells of the connected component.

    A border cell is a cell which satisfies at least one condition:
    1. It touches the boundary of the grid
    2. Or it has a neighbor with a different color

    We mark border cells temporarily with negative original color.
    This helps us identify them later and change their color.
    */

    void dfs(int row, int col, int n, int m,
             int orgCol, vector<vector<bool>>& vis,
             vector<vector<int>>& grid){

        // mark current cell as visited so we do not visit again
        vis[row][col] = true;

        // this variable will help us decide whether current cell is border
        bool isBorder = false;

        // check all 4 directions
        for(int i = 0; i < 4; i++){

            int nr = row + dx[i];
            int nc = col + dy[i];

            // case 1
            // if neighbor is outside grid, current cell is border
            if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                isBorder = true;
            }

            // case 2
            // if neighbor exists but has different color, current cell is border
            else if(abs(grid[nr][nc]) != orgCol){
                isBorder = true;
            }

            // case 3
            // if neighbor has same color and is not visited, explore it using DFS
            else if(!vis[nr][nc]){
                dfs(nr, nc, n, m, orgCol, vis, grid);
            }
        }

        /*
        If current cell is border, mark it with negative original color.
        We use negative sign so that we can later identify border cells easily.
        We do not directly change to new color because it may affect DFS logic.
        */
        if(isBorder){
            grid[row][col] = -orgCol;
        }
    }


    /*
    This function colors the border of the connected component.

    Steps involved

    Step 1
    Find original color of starting cell

    Step 2
    Run DFS to mark all border cells with negative original color

    Step 3
    Traverse entire grid and convert negative original color to required new color

    Step 4
    Return modified grid
    */

    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {

        int n = grid.size();
        int m = grid[0].size();

        // visited array to track explored cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // original color of connected component
        int orgCol = grid[row][col];

        // run DFS to identify border cells
        dfs(row, col, n, m, orgCol, vis, grid);

        /*
        Now traverse grid and convert negative original color to new color.
        Only border cells were marked negative, so only border cells change color.
        */
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == -orgCol){
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};