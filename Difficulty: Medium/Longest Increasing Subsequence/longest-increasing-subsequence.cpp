class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev <= i-1; prev++){
                if(arr[prev] < arr[i]){
                    // can be a part of this subsequence
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};