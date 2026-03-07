class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // as we need to explore paths in same from u to v , direction of directed edges -> we require topological sort

        // firstly make adj list from the given edges
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(colors.size(),0);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // we need a 2d vector(arr[node][color] type) to save , ki particular node pr end honey valey sarey path me se , konsa color max kitni bar aya h
        vector<vector<int>>  t(colors.size(),vector<int>(26,0)) ; // as color are represented through alphabet so, there can be only 26 colors maximum
        queue<int> q;
        // push the nodes with indegree zero 
        for(int i=0;i<colors.size();i++){
            if(indegree[i]==0) q.push(i);
            t[i][colors[i]-'a'] = 1; // as we are starting from this node , so hmey pta us node pr end honey valey sarey path me sirf vhi ek node hoga, toh max color bhi 1 hoga
        }
        int ans = 0;
        int currNodes = 0; // to detect cycles
        while(!q.empty()){
            int node = q.front();
            q.pop();
            currNodes++;
            // har bari check krlo
            ans = max(ans,t[node][colors[node]-'a']);
            // we need to update the t , while exploring the nei
            for(auto nei: adj[node]){
                for(int i=0;i<26;i++){
                    // most important line
                    // dp table me update krtey rhenge parent node tak us color ka count + 1(agr currnode ka color i se same h, kyuki same h tbhi ith color vali column me contribute kr payega)
                    t[nei][i] = max(t[nei][i],t[node][i]+(colors[nei]-'a'==i));
                }
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        // cycle detect hogyi
        if(currNodes<colors.size()){
            return -1;
        }
        return ans;
    }
};