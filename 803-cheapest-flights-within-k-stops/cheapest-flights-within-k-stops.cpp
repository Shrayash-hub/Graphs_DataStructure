class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // making adj list from the given connected flights with there weight
        vector<pair<int, int>> adj[n + 1];
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        // as we are sorting accroding to the number of stops , here normal
        // queue can also work , because we are exploring nodes and each time
        // stopes just incresed by +1 -> similar to binary maze question
        queue<pair<int, pair<int, int>>> q; // {number of stops,{node,distance}}

        // we also need a dist array , which is going to save the current
        // minimum distance of a node from the source
        vector<int> dist(n + 1, 1e9);

        // pushing the source node and marking it in dist vector
        q.push({0, {src, 0}}); // intially we have zero stops

        // applying djikstra algorithm
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int Cstops = temp.first;
            int node = temp.second.first;
            int Cdist = temp.second.second;

            // if current stops exceeds k , no need to process it
            if (Cstops > k)
                continue;
            // lets explore the nei
            for (auto nei : adj[node]) {
                int next = nei.first;
                int weight = nei.second;

                // if current explored distance from source is smaller than previosly explored distance from any other node , then update the distance(shorter one) and push that part in the queue
                if (dist[next] > Cdist + weight) {
                    dist[next] = Cdist + weight;
                    q.push({Cstops + 1, {next, dist[next]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};