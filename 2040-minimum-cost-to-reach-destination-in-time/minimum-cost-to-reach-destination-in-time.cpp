class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        // firstly making adj list through the given connected nodes
        vector<vector<pair<int, int>>> adj(passingFees.size());

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // as we have a weighted graph and we need to find the path with
        // consumes smallest passingFees -> idicates towards Djikstra's algo on
        // the basis of passingFees
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        // {passingFees till current node,{node,distance from source node to
        // current node}} -> we are going to process the paths with less total passingFees first
        vector<int> dist(passingFees.size(), 1e9); // going to store the minimum time taken from the source to node i

        pq.push({passingFees[0], {0, 0}});
        dist[0] = 0;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int currPf = temp.first;
            int node = temp.second.first;
            int currTime = temp.second.second;

            if (currTime > maxTime)
                continue;

            if (node == passingFees.size() - 1)
                return currPf;

            // lets explore all the nei
            for (auto& nei : adj[node]) {
                int next = nei.first;
                int time = nei.second;

                // relaxing the edges on the basis of time taken
                if (currTime + time < dist[next]) {
                    dist[next] = currTime + time;
                    pq.push({currPf + passingFees[next], {next, currTime + time}});
                }
            }
        }
        return -1;
    }
};