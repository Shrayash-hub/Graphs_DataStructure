class Solution {
public:

    /*
    This DFS explores all servers that are connected through same row or same column.

    We mark server as visited by setting grid[i][j] = 0.

    Then we explore entire row and entire column to find other servers
    that can communicate with this server.
    */
    int dfs(vector<vector<int>>& grid, int i, int j){

        int n = grid.size();
        int m = grid[0].size();

        // mark current server as visited
        grid[i][j] = 0;

        // count current server
        int count = 1;


        // explore entire row
        for(int col = 0; col < m; col++){
            if(grid[i][col] == 1){
                count += dfs(grid, i, col);
            }
        }


        // explore entire column
        for(int row = 0; row < n; row++){
            if(grid[row][j] == 1){
                count += dfs(grid, row, j);
            }
        }

        return count;
    }


    /*
    Main logic

    Traverse grid and run DFS for each unvisited server.

    DFS returns size of communication group.

    Only add group size if greater than 1 because single server cannot communicate.
    */
    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1){

                    int groupSize = dfs(grid, i, j);

                    if(groupSize > 1){
                        count += groupSize;
                    }
                }
            }
        }

        return count;
    }
};