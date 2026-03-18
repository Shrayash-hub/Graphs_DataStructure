class DisjointSet{
    vector<int> parent, size;

public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        // initially sab apne parent khud hote h
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    // find with path compression
    int findUPar(int node){
        if(node == parent[node])
            return node;

        // path compression -> tree flat ban jata h
        return parent[node] = findUPar(parent[node]);
    }

    // union by size
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // agar same component me h -> cycle banega
        if(ulp_u == ulp_v) return;

        // choti tree ko badi me attach karo
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {

        // step 1: edges ko (wt, u, v) format me store karo
        vector<pair<int,pair<int,int>>> adj;

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj.push_back({wt,{u,v}});
        }

        // step 2: sort edges by weight
        sort(adj.begin(), adj.end());

        int sum = 0;

        // DSU initialize
        DisjointSet ds(V);

        // step 3: har edge try karo
        for(auto &edge : adj){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            // agar same parent nahi h -> safe edge
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;                 // MST me include karo
                ds.unionBySize(u, v);      // components merge karo
            }
        }

        return sum;
    }
};