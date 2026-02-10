class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> evenCount;
            unordered_set<int> oddCount;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0) {

                    evenCount.insert(nums[j]);

                } else {

                    oddCount.insert(nums[j]);
                }
                if (evenCount.size() == oddCount.size())
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};