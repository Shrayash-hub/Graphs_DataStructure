class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // for a array to be Trionic it should look like
        //    /p\       /
        //   /   \     /
        //  /     \   /
        // /       \q/
        // base cases are 
        int n = nums.size();
        if(n<4) return false;
        if(nums[0]>nums[1] || nums[n-2]>nums[n-1]) return false;

        int i = 0;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        // whole array is increasing
        if(i==n-1) return false;

        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }
        // some of array is increasing and then decreasing
        if(i==n-1) return false;

        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i==n-1) return true;
        return false;
    }
};