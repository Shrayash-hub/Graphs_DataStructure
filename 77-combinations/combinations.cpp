class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& curr,int n,int k,int start){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(start>n){
            return;
        }

        //pick case
        curr.push_back(start);
        solve(ans,curr,n,k-1,start+1);
        // backtrack
        curr.pop_back();

        // not pick case
        solve(ans,curr,n,k,start+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans,curr,n,k,1);
        return ans;
    }
};