class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<pair<int,int>,int>> q;

        // normal visited array se kam nhi chalega yha
        // kyuki same cell par hm alag alag state m a sakte h
        // state depend karegi ki hmarey pas kitne obstacle eliminations(k) bachey hue h

        // thats why visited[row][col][kRemain] track kartey h
        int visited[grid.size()][grid[0].size()][k+1];
        memset(visited,0,sizeof(visited)); // intializing visited

        int steps = 0;

        // as source is (0,0)
        q.push({{0,0},k});
        visited[0][0][k] = 1;


        while(!q.empty()){
            int size = q.size(); 

            while(size--){
                auto temp = q.front();
                q.pop();

                int i = temp.first.first;
                int j = temp.first.second;

                int kRemain = temp.second; // abhi kitney obstacles aur remove kr saktey h

                // destination pr phoch gye
                if(i==grid.size()-1 && j==grid[0].size()-1) 
                    return steps;

                // explore in all the directions
                for(int d=0; d<4; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    // boundary checks
                    if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size()){

                        // agr obstacle h aur kRemain 0 h toh hum cross nhi kar saktey
                        if(grid[ni][nj]==1 && kRemain==0) 
                            continue;

                        // agr obstacle h aur kRemain > 0 h
                        // toh hm obstacle eliminate karke agey badh saktey h
                        else if(grid[ni][nj]==1 && kRemain>0){
                            if(!visited[ni][nj][kRemain-1]){
                                visited[ni][nj][kRemain-1] = 1;
                                q.push({{ni,nj},kRemain-1});
                            }
                        }

                        // agr empty cell h toh normally move kar sakte h
                        else if(grid[ni][nj]==0){
                            if(!visited[ni][nj][kRemain]){
                                visited[ni][nj][kRemain] = 1;
                                q.push({{ni,nj},kRemain});
                            }
                        }
                    }
                }
            }

            // increase the level by 1
            steps++;
        }

        return -1;
    }
};
