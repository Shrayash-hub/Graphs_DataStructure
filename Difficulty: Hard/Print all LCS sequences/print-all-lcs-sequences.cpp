class Solution {
public:
    map<pair<int, int>, set<string>> memo;

    set<string> build(string &s1, string &s2, vector<vector<int>> &dp, int i, int j) {
        // base case
        if (i == 0 || j == 0) return {""};

        // if already computed, return cached result
        if (memo.count({i, j})) return memo[{i, j}];

        set<string> ans;

        // if characters match, include this character
        if (s1[i - 1] == s2[j - 1]) {
            set<string> temp = build(s1, s2, dp, i - 1, j - 1);

            for (auto &str : temp) {
                ans.insert(str + s1[i - 1]);
            }
        }
        else {
            // go up if it keeps LCS optimal
            if (dp[i - 1][j] == dp[i][j]) {
                set<string> temp = build(s1, s2, dp, i - 1, j);
                ans.insert(temp.begin(), temp.end());
            }

            // go left if it keeps LCS optimal
            if (dp[i][j - 1] == dp[i][j]) {
                set<string> temp = build(s1, s2, dp, i, j - 1);
                ans.insert(temp.begin(), temp.end());
            }
        }

        // store and return
        return memo[{i, j}] = ans;
    }

    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        // Step 1: build LCS length table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: reconstruct all LCS using memoized backtracking
        set<string> ans = build(s1, s2, dp, n, m);

        return vector<string>(ans.begin(), ans.end());
    }
};