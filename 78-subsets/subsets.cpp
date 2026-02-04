class Solution {
public:
    void solve(vector<int>& nums,int n,int index,vector<vector<int>> &ans,vector<int> &curr){
        if(n==index){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(nums,n,index+1,ans,curr);

        curr.pop_back();
        solve(nums,n,index+1,ans,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        solve(nums,nums.size(),index,ans,curr);
        return ans;

    }
};