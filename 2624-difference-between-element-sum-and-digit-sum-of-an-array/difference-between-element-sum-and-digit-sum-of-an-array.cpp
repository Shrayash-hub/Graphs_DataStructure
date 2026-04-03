class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int ESum = 0;
        int DSum = 0;

        for (int i = 0; i < n; i++) {
            ESum += nums[i];

            while (nums[i]) {
                DSum += nums[i] % 10;
                nums[i] /= 10;
            }
        }

        return abs(ESum - DSum);
    }
};