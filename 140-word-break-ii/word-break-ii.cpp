class Solution {
public:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> solve(int start, string &s) {
        // If already computed
        if (memo.count(start)) 
            return memo[start];

        vector<string> result;

        // Base case
        if (start == s.length()) {
            result.push_back("");
            return result;
        }

        // Try all possible substrings
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);

            if (dict.count(word)) {
                vector<string> restSentences = solve(end, s);

                for (string &sentence : restSentences) {
                    if (sentence == "")
                        result.push_back(word);
                    else
                        result.push_back(word + " " + sentence);
                }
            }
        }

        memo[start] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();
        return solve(0, s);
    }
};
