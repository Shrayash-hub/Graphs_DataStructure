class Solution {
    int maxOR = 0;
    int count = 0;

    public: 
    int countMaxOrSubsets(vector<int> nums) {
        //find max OR
        for (auto num : nums) {
            maxOR |= num;
        }

        dfs(nums, 0, 0);

        return count;
    }

    void dfs(vector<int> nums, int index, int currOR) {
        // Base Case
        if (index == nums.size()) {
            if (currOR == maxOR) count++;
            return;
        }

        //include current element
        dfs(nums, index + 1, currOR | nums[index]);

        //exclude current element
        dfs(nums, index + 1, currOR);
    }
};