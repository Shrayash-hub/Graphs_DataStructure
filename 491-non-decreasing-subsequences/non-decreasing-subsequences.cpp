class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>& curr,vector<vector<int>>& ans){
        // base case 
        if(curr.size()>=2){
            ans.push_back(curr);
        }
        // set le lenge taki duplicate subsequences na a jaye ans me
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++){
            // tbhi insert krenge jab , ye element , previous inserted element se bada hoga
            if((curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])==st.end())){
                curr.push_back(nums[i]); // pick condition
                solve(nums,i+1,curr,ans);
                // backtrack it -> not pick condition
                curr.pop_back();
                
                // updating set 
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 2d vector for storing the result
        vector<vector<int>> ans;

        // vector to track the current subsequence
        vector<int> curr;

        // calling recursive function -> which is going to update the ans
        // we need to start from index = 0;
        solve(nums,0,curr,ans);
        return ans;

    }
};