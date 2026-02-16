class Solution {
public:
    int t[201][1001];
    int solve(int k,vector<int> nums,
               int index) {
        if (k == 0) {
            return 1;
        }
        if (index >= nums.size() || k<0) {
            return 0;
        }
        if(t[index][k]!=-1) return t[index][k];

        // pick case
        
        int takeIdx = solve(k-nums[index],nums,0);
    

        // not pick case
        int notTakeIdx = solve(k,nums,index+1);
        return t[index][k] = takeIdx + notTakeIdx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(target,nums,0);
        
    }
};