class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void updateFireTime(vector<vector<int>>& grid, vector<vector<int>>& fireTime){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        int currTime = 0;

        // initialize fireTime matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){  // fire
                    fireTime[i][j] = currTime;
                    q.push({i,j});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 2){ // wall
                    fireTime[i][j] = -1;
                }
            }
        }

        // BFS to fill fireTime
        while(!q.empty()){
            currTime++;
            int size = q.size();

            for(int k = 0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int l = 0; l < 4; l++){
                    int newi = i + dx[l];
                    int newj = j + dy[l];

                    if(newi>=0 && newj>=0 && newi<n && newj<m &&
                       visited[newi][newj]==false &&
                       fireTime[newi][newj]!=-1){

                        fireTime[newi][newj] = currTime;
                        q.push({newi,newj});
                        visited[newi][newj] = true;
                    }
                }
            }
        }
    }

    // YOUR isPossible from screenshot (same logic)
    bool isPossible(int t, vector<vector<int>>& fireTime){

        int m = fireTime.size();
        int n = fireTime[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        int currTime = t;

        // if fire reaches start before or at wait time
        if(fireTime[0][0] <= currTime)
            return false;

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){

            currTime++;

            int size = q.size();

            for(int i = 0; i < size; i++){

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++){

                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx<0 || ny<0 || nx>=m || ny>=n ||
                       fireTime[nx][ny]==-1 ||
                       visited[nx][ny])
                        continue;

                    if(nx==m-1 && ny==n-1 &&
                       currTime <= fireTime[m-1][n-1])
                        return true;

                    if(currTime < fireTime[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> fireTime(n, vector<int>(m, INT_MAX));

        updateFireTime(grid, fireTime);

        int ans = -1;
        int left = 0;
        int right = m*n + 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(isPossible(mid, fireTime)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans == m*n + 1 ? 1000000000 : ans;
    }
};
