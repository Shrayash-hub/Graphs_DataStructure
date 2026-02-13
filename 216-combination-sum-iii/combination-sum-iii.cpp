class Solution {
public:
    void solve(int i, int currSum, int k, int n, vector<int>& curr,
               vector<vector<int>>& ans) {
        // base cases
        if (k == 0 && currSum == n) {
            ans.push_back(curr);
            return;
        }

        if (i > 9 || k < 0 || currSum > n) return;

        // pick
        currSum += i;
        curr.push_back(i);
        solve(i + 1, currSum, k - 1, n, curr, ans);
        curr.pop_back();
        currSum -= i;

        // not pick
        solve(i + 1, currSum, k, n, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, 0, k, n, curr, ans);
        return ans;
    }
};