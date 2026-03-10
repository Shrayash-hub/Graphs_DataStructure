class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        // making adj matrix from the given connected nodes {node,probability}
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // we need to implement djikstra's algorithm but using max heap , as
        // here we need path with maximum sum of weights
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        
        // probability for source node is going to be 1.0 , kyuki source pe khadey
        // hokey khud ko traverse krney ki probabily obviously 100% hogi
        pq.push({1.0, start});
        dist[start] = 1.0;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int node = temp.second;
            double Cprob = temp.first;

            // lets explore the nei
            for (auto nei : adj[node]) {
                int next = nei.first;
                double prob = nei.second;

                // here we will update is we got path with greater probability
                if (Cprob * prob > dist[next]) {
                    dist[next] = Cprob * prob;
                    pq.push({Cprob * prob, next});
                }
            }
        }
        return dist[end];
    }
};