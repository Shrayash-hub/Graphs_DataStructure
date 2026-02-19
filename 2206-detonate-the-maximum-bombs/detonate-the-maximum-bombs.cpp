class Solution {
public:
    typedef long long LL;

    void dfs(int start,vector<int> adj[],unordered_set<int> &visited){
        visited.insert(start);
        for(auto &it: adj[start]){
            if(visited.find(it)==visited.end()){
                dfs(it,adj,visited);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        // firslty we will build the adja. list -> ki konsa bomb , kis kis bomb ko affect kr skta h , extra kam yhi pr h , baki toh normal dfs h
        for(int i=0;i<bombs.size();i++){
            for(int j=0;j<bombs.size();j++){
                if(i==j) continue;
                // taking out coordinates and radius of the bombs
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                // finding square of distance between the centers of two bombs
                LL d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

                // if radius of one bomb is greater than the distance between the center of two bombs , so that bomb can detonate the other bomb
                if(LL(r1*r1)>=d){
                    adj[i].push_back(j);
                }
            }
        }
        int result = 0;
        // having a visited set , that going to check ki kon kon se bomb detonate ho gye h
        unordered_set<int> visited;
        for(int i=0;i<bombs.size();i++){
            // calling dfs for each bomb
            dfs(i,adj,visited);
            // calculating the number 0f bombs that bomb can detonate
            int count = visited.size();

            // finding max number of bombs a bomb can detonate
            result = max(result,count);

            // for each bomb new visted set will be required
            visited.clear();
        }
        return result;
    }
};