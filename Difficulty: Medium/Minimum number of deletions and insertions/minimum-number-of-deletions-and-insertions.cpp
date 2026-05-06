class Solution {

  public:
    
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // if char at same index matches then , these matched char will be contribute to the LCS
                // so ans will have 1 + now move the pointer step backward -> bachey hue strings me maching chars find krney k liye
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                // if not matched then there will be 2 diffrent cases
                // either reduce i or either reduce 0 and take max of them
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int LengthLCS = lcs(s1,s2);
        
        int insertions = s1.size() - LengthLCS;
        int deletions = s2.size() - LengthLCS;
        
        return insertions + deletions;
    }
};