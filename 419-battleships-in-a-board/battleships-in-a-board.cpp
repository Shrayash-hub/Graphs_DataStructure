class Solution {
public:

    int dx[2] = {1,0};
    int dy[2] = {0,1};

    void dfs(vector<vector<char>>& board, int row, int clm, vector<vector<int>> &visited){

        visited[row][clm] = 1;

        for(int i=0;i<2;i++){

            int newR = row + dx[i];
            int newC = clm + dy[i];

            if(newR>=0 && newC>=0 && newR<board.size() && newC<board[0].size()
               && visited[newR][newC]==0 && board[newR][newC]=='X'){

                dfs(board,newR,newC,visited);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int cnt = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(board[i][j]=='X' && visited[i][j]==0){

                    cnt++;

                    dfs(board,i,j,visited);
                }
            }
        }

        return cnt;
    }
};
