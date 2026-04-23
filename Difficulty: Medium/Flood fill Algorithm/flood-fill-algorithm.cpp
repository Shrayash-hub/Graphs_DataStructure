class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {

        // already have newColor
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc]==newColor){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==originalColor){
                    image[nr][nc] = newColor;
                    q.push({nr,nc});
                }
            }
            
        }
        return image;
    }
};