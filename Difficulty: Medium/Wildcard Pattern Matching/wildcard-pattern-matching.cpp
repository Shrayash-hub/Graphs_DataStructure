class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int m = txt.size();
        int n = pat.size();
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        
        // base cases
        
        // 1. if both the string is exhausted 
        dp[0][0] = true;
        
        // 2. if the first string is exhausted and second string is still remain
        for(int j = 1; j <= n; j++) dp[0][j] = false;
        
        // 3. if second string is exhausted and first string have only stars
        for(int i = 1; i <= n; i++){
            bool flag = true;
            for(int x = 1; x <= i ; x++){
                if(pat[x-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(txt[i-1] == pat[j-1] || pat[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pat[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};