class Solution {
public:
    int dx[2] = {1, 0}; // down, right
    int dy[2] = {0, 1};

    void dfs(vector<vector<int>>& land, vector<vector<int>>& ans,
             vector<int>& quad, int i, int j) {

        land[i][j] = 0;

        for (int k = 0; k < 2; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < land.size() && nj < land[0].size() && land[ni][nj] == 1) {

                // update bottom right , as bottom right part k cordinates sabse purey farmland k kisi bhi part se badey hongey
                if (ni > quad[2])
                    quad[2] = ni;
                if (nj > quad[3])
                    quad[3] = nj;

                dfs(land, ans, quad, ni, nj);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (land[i][j] == 1) {

                    vector<int> quad(4);
                    quad[0] = i;
                    quad[1] = j;
                    quad[2] = i; // filhal k liye isi ko bottome right consider
                                 // kr letey h (i,j)
                    quad[3] = j;

                    dfs(land, ans, quad, i, j);

                    ans.push_back(quad);
                }
            }
        }
        return ans;
    }
};