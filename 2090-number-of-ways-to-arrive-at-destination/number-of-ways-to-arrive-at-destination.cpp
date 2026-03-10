class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        // making adj list from the given connected nodes
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // we need a priority queue to implement the Djikstra's algo
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        // also we need a distance vector to store  the shortest distance from
        // the source node
        vector<long long> dist(n, LLONG_MAX);
        // we need a ways vector to store the , ways to reach that node from the
        // source node
        vector<int> ways(n, 0);

        // pushing the source node in queue and marking dist as as 0
        pq.push({0, 0});
        dist[0] = 0;

        // we know that there are only 1 ways to reach source from soruce itself
        ways[0] = 1;

        // applying djikstra's algo
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            long long Ctime = temp.first;
            int node = temp.second;

            // ignore older longer paths
            if (Ctime > dist[node]) continue;
            
            // exploring all the nei
            for (auto nei : adj[node]) {
                int next = nei.first;
                int time = nei.second;

                // we get a shorter distance path update it and at the same time
                // update the ways as The number of ways becomes the ways of the
                // parent
                if (Ctime + time < dist[next]) {
                    dist[next] = Ctime + time;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                }
                // we already found a shortest path to next, but now another
                // route with the same distance appears. so add the number
                // number of ways from the parent as every shortest path to node
                // can extend to next
                else if (Ctime + time == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};