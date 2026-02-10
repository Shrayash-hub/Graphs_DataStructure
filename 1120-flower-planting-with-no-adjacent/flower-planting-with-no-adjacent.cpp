class Solution {
public:
    bool isSafe(int garden, vector<int> &flower, vector<vector<int>> &adj,int n, int flo){
        for(auto neig: adj[garden]){
            if(flower[neig]==flo){
                return false;
            }
        }
        return true;
    }
    bool solve(int garden, vector<int> &flower, vector<vector<int>> &adj,int n, int m){
        if(garden==n+1) return true;
        // trying all the colors to that vertex
        for(int i=1;i<=m;i++){
            if(isSafe(garden,flower,adj, n, i)){
                // place color : as it is safe for now
                flower[garden] = i;
                // recursively calling for next node
                if(solve(garden+1,flower,adj, n, m)) return true;
                
                // if at a point we reach to a dead end , so backtrack
                flower[garden] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
         // code here
        // building adj list, where we will save ki kis garden se konsa konsa garden connected h ,like:
        // 1 -> {2,3}
        // 2 -> {1,3}
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<paths.size();i++){
            int u = paths[i][0];
            int v = paths[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // we need a vector flower -> which is going to save , ki konsi garden  ko konsa flower assign hua h
        vector<int> flower(n+1,0); // 0 means koi bhi color assign nhi hua h
        
        // calling recursive function
        solve(1,flower,adj,n,4);
        flower.erase(flower.begin());

        return flower;
        
    }
};