class Robo {
public:
    int pos, range;
    Robo(int p, int r) : pos(p), range(r) {}
};

class Solution {
public:
    vector<vector<int>> dp;

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {

        int n = robots.size();

        // Build robots
        vector<Robo> robos;
        for (int i = 0; i < n; i++) {
            robos.emplace_back(robots[i], distance[i]);
        }

        // Sort robots and walls
        sort(robos.begin(), robos.end(), [](Robo &a, Robo &b) {
            return a.pos < b.pos;
        });
        sort(walls.begin(), walls.end());

        dp.assign(n, vector<int>(2, -1));

        return solve(0, 0, robos, walls);
    }

    int solve(int idx, int prevDir, vector<Robo>& robos, vector<int>& walls) {

        if (idx == robos.size()) return 0;

        if (dp[idx][prevDir] != -1) return dp[idx][prevDir];

        Robo &curr = robos[idx];

        // -------------------------
        // OPTION 1: GO LEFT
        // -------------------------
        int leftBound = max(0, curr.pos - curr.range);

        if (idx > 0) {
            if (prevDir == 0) {
                leftBound = max(leftBound, robos[idx - 1].pos + 1);
            } else {
                leftBound = max(leftBound,
                                robos[idx - 1].pos + robos[idx - 1].range + 1);
            }
        }

        int leftWalls = countWalls(leftBound, curr.pos, walls);
        int optionLeft = leftWalls + solve(idx + 1, 0, robos, walls);

        // -------------------------
        // OPTION 2: GO RIGHT
        // -------------------------
        int rightBound = curr.pos + curr.range;

        if (idx < robos.size() - 1) {
            rightBound = min(rightBound, robos[idx + 1].pos - 1);
        }

        int rightWalls = countWalls(curr.pos, rightBound, walls);
        int optionRight = rightWalls + solve(idx + 1, 1, robos, walls);

        return dp[idx][prevDir] = max(optionLeft, optionRight);
    }

    // Count walls in [lb, rb]
    int countWalls(int lb, int rb, vector<int>& walls) {

        int leftIdx = lowerBound(walls, lb);
        int rightIdx = upperBound(walls, rb);

        if (leftIdx == -1 || rightIdx == -1 || leftIdx > rightIdx)
            return 0;

        return rightIdx - leftIdx + 1;
    }

    // First index >= target
    int lowerBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    // Last index <= target
    int upperBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};