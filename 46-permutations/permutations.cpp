class Solution {
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans){
        // base case -> if index covered all the elements
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            // covering all the remaining elements
            swap(nums[index],nums[i]);

            // call for swaping at next index
            solve(index+1,nums,ans);

            // backtracking for covering another cases
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};