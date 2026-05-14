// User function Template for C++
class Solution {
  public:
    int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp){
        // empty string
        if(i > j) return 0;
        // if single element left
        if(i == j){
            if(isTrue == true){
                return s[i] == 'T';
            }
            else{
                return s[i] == 'F';
            }
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ans = 0;
        for(int k = i+1; k <= j-1; k+=2){
            int lt = solve(s,i,k-1,true, dp);
            int lf = solve(s,i,k-1,false, dp);
            int rt = solve(s,k+1,j,true, dp);
            int rf = solve(s,k+1,j,false, dp);
            
            if(s[k] == '&'){
                if(isTrue == true){
                    ans+= (lt * rt);
                }
                else{
                    ans+= (lf * rf);
                    ans+= (lf * rt);
                    ans+= (lt * rf);
                }
            }
            else if(s[k] == '|'){
                if(isTrue == true){
                    ans+= (lt * rt);
                    ans+= (lt * rf);
                    ans+= (lf * rt);
                }
                else{
                    ans+= (lf * rf);
                }
            }
            else if(s[k] == '^'){
                if(isTrue == true){
                    ans += (lf * rt);
                    ans += (lt * rf);
                }
                else{
                    ans += (lf * rf);
                    ans += (lt * rt);
                }
            }
        }
        return dp[i][j][isTrue] = ans;
    }
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1,vector<int>(2,-1)));
        int i = 0;
        int j = s.size()-1;
        bool isTrue = true;
        return solve(s, i, j, isTrue, dp);
    }
};