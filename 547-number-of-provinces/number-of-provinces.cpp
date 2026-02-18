class Solution {
public:
    void dfs(int start,vector<int> adj[],vector<int> &visited){
        visited[start]=1;
        
        for(auto nei: adj[start]){
            if(visited[nei]!=1){
                visited[nei]=1;
                dfs(nei,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};