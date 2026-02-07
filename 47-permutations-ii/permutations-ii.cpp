class Solution {
public:
    void solve(int index,
               vector<int>& nums,
               vector<vector<int>>& ans) {

        // all positions are fixed now
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // set to track values used at a level
        unordered_set<int> usedAtLevel;

        // try swaping each possible value at position 'index'
        for (int i = index; i < nums.size(); i++) {

            // if this value is already used at this level, skip it
            if (usedAtLevel.count(nums[i]))
                continue;

            // mark value as used at this level
            usedAtLevel.insert(nums[i]);

            // nums[i] at position index
            swap(nums[index], nums[i]);

            // recurse for next index
            solve(index + 1, nums, ans);

            // backtrack restore original order
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};
