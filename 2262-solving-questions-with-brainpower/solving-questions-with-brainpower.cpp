class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // state will be the points we can earn from starting at index i

        // at every question , we have only 2 choices , either to solve this question and earn p[i] points  and skip bp[i] question  OR to skip this question and solve next question ( take or not take type question )

        // if we take/ solve current question , then points will be sum of current question points + points of question at index i + bp + 1 (as we need to skip bp[i] questions) 
        // and if we skip toh dp[i] will be next question k dp value k equal

        // -> as we can see future state or depend krta h -> so we will start filling it from backward 

        for (int i = n - 1; i >= 0; i--) {
            long long points = questions[i][0];
            int bp = questions[i][1];

            // take option
            long long take = points;
            if (i + bp + 1 < n) {
                take += dp[i + bp + 1];
            }

            // skip option
            long long skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};