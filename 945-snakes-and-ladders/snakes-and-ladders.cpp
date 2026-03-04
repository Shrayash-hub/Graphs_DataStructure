class Solution {
public:

    // convert square number to board coordinates
    pair<int,int> getCoord(int num, int n){

        int r = (num-1)/n;
        int c = (num-1)%n;

        if(r % 2 == 1)
            c = n-1-c;

        r = n-1-r;

        return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        queue<int> q;
        vector<bool> visited(n*n+1,false);

        q.push(1);
        visited[1] = true;

        int moves = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int curr = q.front();
                q.pop();

                if(curr == n*n)
                    return moves;

                for(int dice=1; dice<=6; dice++){

                    int next = curr + dice;

                    if(next > n*n)
                        break;

                    auto [r,c] = getCoord(next,n);

                    if(board[r][c] != -1)
                        next = board[r][c];

                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};