class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        vector<int> dist(1001, 1e9);   // numbers allowed in range 0..1000
        
        queue<pair<int,int>> q;        // {steps , value}
        
        q.push({0, start});
        dist[start] = 0;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int Csteps = temp.first;
            int node = temp.second;
            
            for(int i = 0; i < nums.size(); i++){
                
                int add = node + nums[i];
                int sub = node - nums[i];
                int xr  = node ^ nums[i];
                
                vector<int> nextVals = {add, sub, xr};
                
                for(int next : nextVals){
                    
                    if(next == goal)
                        return Csteps + 1;
                    
                    if(next >= 0 && next <= 1000 && dist[next] > Csteps + 1){
                        dist[next] = Csteps + 1;
                        q.push({dist[next], next});
                    }
                }
            }
        }
        
        return -1;
    }
};