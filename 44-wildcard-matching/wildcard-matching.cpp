class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // dp state is going to save that , if stating i characters of s is
        // matching with stating j character of p -> s[0...i-1] matches with
        // p[0...j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case -> empty string matches with empty pattern
        dp[0][0] = true;

        // empty string and non empty pattern
        
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                // suppose in patter there is only '*' (ex: "**"), this is going to match the empty string -> thats why ye condition likhi h , ki previous state se utha lo value 
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // case1: if string char matches with the pattern char , then look for the value , when those char. were not in the s and p -> dp[i-1][j-1]
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // if pattern have '*' , so there will be 2 chances 
                // 1. "abc" & "a*bc" when * doesnt matches with any character -> so we ignore it or we can think like its acting like empty char -> we will look for the value , when p dosent have '*' -> dp[i][j-1]
                // 2. "abbbbc" & "a*c" , when * consumes many char. -> pattern same rhega string ka ek ek char km hota jayega
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};