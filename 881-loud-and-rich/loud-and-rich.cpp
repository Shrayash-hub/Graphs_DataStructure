class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // build graph: richer -> poorer
        for (auto &r : richer) {
            int a = r[0]; // richer
            int b = r[1]; // poorer

            graph[a].push_back(b);
            indegree[b]++;
        }

        // initially each person is their own quietest
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = i;

        // kahn's algorithm
        queue<int> q;

        // start with nodes having indegree 0 (no one richer)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {

                // propagate quietest
                if (quiet[ans[u]] < quiet[ans[v]]) {
                    ans[v] = ans[u];
                }

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans;
    }
};