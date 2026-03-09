class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // normal shortest path have,  distance = sum of weights
        // this problem: distance = maximum weight seen so far
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 1e9));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        vis[0][0] = 0; // stores minimum effort required to reach cell (i,j)
        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            auto temp = pq.top();
            pq.pop();

            int diff = temp.first;
            int row = temp.second.first;
            int clm = temp.second.second;

            // once we pop the smallest distance node from pq,
            // we have already found its optimal answer
            if (row == n - 1 && clm == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {

                int nr = row + dx[i];
                int nc = clm + dy[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    // new_effort = max(current_effort , edge_weight)
                    // edge_weight = |height[r][c] - height[nr][nc]|
                    int newEff =
                        max(diff, abs(heights[row][clm] - heights[nr][nc]));

                    // if we got any less effort path , we will update the vis matrix
                    if (newEff < vis[nr][nc]) {
                        vis[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        // destination not rechable
        return 0;
    }
};