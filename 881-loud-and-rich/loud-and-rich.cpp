class Solution {
public:

    int dfs(int person,
            vector<vector<int>>& graph,
            const vector<int>& quiet,
            vector<int>& memo) {

        if (memo[person] != -1)
            return memo[person];

        int quietest = person;

        for (int nei : graph[person]) {
            int candidate = dfs(nei, graph, quiet, memo);

            if (quiet[candidate] < quiet[quietest])
                quietest = candidate;
        }

        memo[person] = quietest;
        return quietest;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();
        vector<vector<int>> graph(n);

        for (auto &r : richer) {
            int a = r[0];
            int b = r[1];
            graph[b].push_back(a);
        }

        vector<int> memo(n, -1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = dfs(i, graph, quiet, memo);

        return ans;
    }
};