class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int maxi = INT_MIN;
        if (n == 2)
            return stones[n - 1] - stones[0];
        for (int i = 0; i < n - 2; i++) {
            // finding difference b/w alternate stone positions
            // max cost found is the min cost of the path
            maxi = max(maxi, stones[i + 2] - stones[i]);
        }
        return maxi;
    }
};