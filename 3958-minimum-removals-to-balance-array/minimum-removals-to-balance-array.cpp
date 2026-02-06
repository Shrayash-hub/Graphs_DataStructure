class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            
            
            // boundary check
            while (j < n && nums[j] <= (long long) nums[i] * k) {
                j++;
            }

            // longest subarray length
            maxi = max(maxi, j - i);
        }

        // minimum removals
        return n - maxi;
    }
};