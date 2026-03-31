class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        // simply jinki indegree zero h , unko include krna padhega, kyuki unpey phochney ka koi aur path nhi h
        vector<int> ans;
        for (auto edge : edges) {
            int v = edge[1];
            indegree[v]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};