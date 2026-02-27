class Solution {
public:
    vector<vector<int>> buildMatrix(int k, 
        vector<vector<int>>& rowConditions, 
        vector<vector<int>>& colConditions) {

        // row graph
        vector<vector<int>> adj1(k+1);
        vector<int> indegreeRow(k+1, 0);

        for(int i = 0; i < rowConditions.size(); i++){
            int u = rowConditions[i][0];
            int v = rowConditions[i][1];
            adj1[u].push_back(v);
            indegreeRow[v]++;
        }

        // clm graph
        vector<vector<int>> adj2(k+1);
        vector<int> indegreeCol(k+1, 0);

        for(int i = 0; i < colConditions.size(); i++){
            int u = colConditions[i][0];
            int v = colConditions[i][1];  
            adj2[u].push_back(v);
            indegreeCol[v]++;
        }

        // topo for Rows (level store kar letey h)
        queue<int> q1;
        for(int i = 1; i <= k; i++){
            if(indegreeRow[i] == 0)
                q1.push(i);
        }

        vector<int> rowLevel(k+1, 0);
        int level = 0;
        int count1 = 0;

        while(!q1.empty()){
            int node = q1.front();
            q1.pop();

            rowLevel[node] = level++;   // level save krlo
            count1++;

            for(auto it : adj1[node]){
                indegreeRow[it]--;
                if(indegreeRow[it] == 0)
                    q1.push(it);
            }
        }

        if(count1 != k) return {};   // cycle hue toh

        // topo for Clms
        queue<int> q2;
        for(int i = 1; i <= k; i++){
            if(indegreeCol[i] == 0)
                q2.push(i);
        }

        vector<int> colLevel(k+1, 0);
        level = 0;
        int count2 = 0;

        while(!q2.empty()){
            int node = q2.front();
            q2.pop();

            colLevel[node] = level++;   // level save
            count2++;

            for(auto it : adj2[node]){
                indegreeCol[it]--;
                if(indegreeCol[it] == 0)
                    q2.push(it);
            }
        }

        if(count2 != k) return {};   // cycle hue toh

        
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i = 1; i <= k; i++){
            ans[rowLevel[i]][colLevel[i]] = i;
        }

        return ans;
    }
};