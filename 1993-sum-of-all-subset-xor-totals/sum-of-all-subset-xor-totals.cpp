class Solution {
public:

    int dfs(vector<int>& nums, int index, int currXor) {

        // base case
        if(index == nums.size()) {
            return currXor;
        }
        // include the current element
        int include = dfs(nums, index + 1, currXor ^ nums[index]);

        // exclude the current element
        int exclude = dfs(nums, index + 1, currXor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {

        return dfs(nums, 0, 0);
    }
};
