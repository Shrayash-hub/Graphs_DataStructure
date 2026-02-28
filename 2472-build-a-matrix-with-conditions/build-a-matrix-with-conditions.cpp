class Solution {
public:
    // Topological Sort Function
    vector<int> topoSort(int k, vector<vector<int>>& adj,
                         vector<int>& indegree) {

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> levelPos(k + 1, 0);
        int level = 0;
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            levelPos[node] = level++;
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // If cycle exists
        if (count != k)
            return {};

        return levelPos;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        //  Row Graph
        vector<vector<int>> adj1(k + 1);
        vector<int> indegreeRow(k + 1, 0);

        for (auto& cond : rowConditions) {
            int u = cond[0];
            int v = cond[1];
            adj1[u].push_back(v);
            indegreeRow[v]++;
        }

        // Column Graph
        vector<vector<int>> adj2(k + 1);
        vector<int> indegreeCol(k + 1, 0);

        for (auto& cond : colConditions) {
            int u = cond[0];
            int v = cond[1];
            adj2[u].push_back(v);
            indegreeCol[v]++;
        }

        // her we will be saving the topological position of every node
        vector<int> rowLevel = topoSort(k, adj1, indegreeRow);
        if (rowLevel.empty())
            return {}; // cycle in row graph

        vector<int> colLevel = topoSort(k, adj2, indegreeCol);
        if (colLevel.empty())
            return {}; // cycle in column graph

        // building matrix
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i++) {
            ans[rowLevel[i]][colLevel[i]] = i;
        }

        return ans;
    }
};