class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int FreshOranges = 0;
        
        queue<pair<int,int>> q; // for {row,clm}
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( mat[i][j] == 1 ){
                    FreshOranges++;
                }
                else if( mat[i][j] == 2 ){
                    q.push( {i,j} );
                }
            }
        }
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int time = 0;
        while( !q.empty() && FreshOranges > 0 ){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto [r , c] = q.front();
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] == 1){
                        mat[nr][nc] = 2;
                        FreshOranges--;
                        q.push( {nr,nc} );
                    }
                }
            }
            time++;
        }
        return (FreshOranges == 0) ? time : -1;
    }
};