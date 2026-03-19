class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // initially sab apne parent khud hote h
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // find with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        // path compression -> tree flat ban jata h
        return parent[node] = findUPar(parent[node]);
    }

    // union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // agar same component me h -> cycle banega
        if (ulp_u == ulp_v)
            return;

        // choti tree ko badi me attach karo
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // as the dimensions of matrix is not given , find the maxRow and maxClm
        int maxRow = -1;
        int maxClm = -1;

        for (auto& edge : stones) {
            maxRow = max(maxRow, edge[0]);
            maxClm = max(maxClm, edge[1]);
        }

        // now we need to find the number of non connected components using
        // Disjoint set union

        // treating each row and each clm as a node
        // rows ko normally store kr leneg but clm ko map kr lenge -> rowNumber + maxRow + 1 se
        
        DisjointSet ds(maxRow + maxClm + 1);
        unordered_map<int, int> stoneNodes;
        for (auto& edge : stones) {
            ds.unionBySize(edge[0], edge[1] + maxRow + 1);
            // map me sirf vhi nodes store ho rhey h jhn actual stones exist kartey h -> kyuki kuch ese bhi rows aur clm h , jha ek bhi stone nhi h -> but vo single component ki trah count ho jayengi -> so to avoid it use map
            stoneNodes[edge[0]] = 1;
            stoneNodes[edge[1] + maxRow + 1] = 1;
        }
        int cnt = 0;
        for (auto& it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }

        // in one connected component of size k, we can remove k - 1 stones (leaving 1 behind). so answer = total stones - number of connected components
        return stones.size() - cnt;
    }
};