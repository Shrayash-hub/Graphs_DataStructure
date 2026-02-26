class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the directions and counting the indegree according to those
        // directions
        vector<int> indegree(graph.size(), 0);
        const int n = graph.size();
        vector<int> adj[n];
        for (int i = 0; i < graph.size(); i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        // insert the node with indegree zero to the queue as they are safe nodes
        for (int i = 0; i < graph.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // by bfs apply the topological sort , node that have cycle and have a path , that node going to end at the safe nodes then they will be left and not added to the ans vector
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};