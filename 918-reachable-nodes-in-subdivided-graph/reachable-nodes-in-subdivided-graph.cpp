class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

        // adjacency list
        // node -> {neighbor, number of subdivided nodes}
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // max heap storing {remaining_moves , node}
        priority_queue<pair<int,int>> pq;

        // dist[i] = maximum remaining moves when reaching node i
        vector<int> dist(n,-1);

        pq.push({maxMoves,0});
        dist[0] = maxMoves;

        while(!pq.empty()){

            auto [moves,node] = pq.top();
            pq.pop();

            // if we already reached this node with more moves earlier
            // this state is useless
            if(moves < dist[node]) continue;

            for(auto [nei,w] : adj[node]){

                // cost to reach neighbor
                // need to cross w subdivided nodes + 1 edge
                int nextMoves = moves - w - 1;

                // if we still have moves and found a better path
                if(nextMoves >= 0 && nextMoves > dist[nei]){

                    dist[nei] = nextMoves;
                    pq.push({nextMoves,nei});
                }
            }
        }

        int ans = 0;

        // count reachable original nodes
        for(int d : dist)
            if(d >= 0) ans++;

        // count reachable subdivided nodes
        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            // moves available from both sides
            int a = dist[u] < 0 ? 0 : dist[u];
            int b = dist[v] < 0 ? 0 : dist[v];

            // reachable subdivided nodes
            ans += min(w , a + b);
        }

        return ans;
    }
};
