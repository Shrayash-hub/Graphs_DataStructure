class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();

        int maxLen = INT_MIN;
        for(auto word : wordDict){
            maxLen = max(maxLen,(int)word.size());
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;  // base case

        for (int i = 1; i <= n; i++) {

            // check only substrings of length <= maxLen
            for (int j = i - 1; j >= max(0, i - maxLen); j--) {

                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // No need to check further
                }
            }
        }

        return dp[n];
    }
};