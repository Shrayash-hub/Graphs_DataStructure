// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        // Because of modulo operation, every possible value we can reach lies between: 0 -> 9999
        // that why mex number of nodes in a graphh can be 100000 -> thats why size is 100000
        vector<int> dist(100000,1e9); // its going to store , minimum number of steps to get multiplication i

        queue<pair<int,int>> q; // {steps,multiplication}
        
        q.push({0,start});
        dist[start] = 0;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int Csteps = temp.first;
            int node = temp.second;
            
            if(node==end){
                return Csteps;
            }
            
            // check by multiplying each element of array
            for(int i=0;i<arr.size();i++){
                int next = (node * arr[i]) % 100000;   

                if(dist[next] > Csteps + 1){            
                    dist[next] = Csteps + 1;
                    q.push({dist[next], next});
                }
            }
        }
        return -1;
    }
};
