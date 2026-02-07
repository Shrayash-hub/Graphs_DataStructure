class Solution {
public:
    void solve(int index,vector<int> &nums,vector<vector<int>> &ans,vector<int> &curr){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(i+1,nums,ans,curr);
            curr.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,curr);
        return ans;
    }
};