class DisjointSet{

public:
    vector<int> parent, size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];
            ds.unionBySize(u, v);
        }
        // counting how many disconnected components exist
        int comp = 0;
        for(int j = 0; j < n; j++){
            // if a node is its own ultimate parent , then its and another component
            if(ds.parent[j] == j) comp++; 
        }

        // as long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
        if(connections.size()>=n-1) return comp-1;
        return -1;
    }
};