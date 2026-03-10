class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // making adj matrix from the given connected nodes
        vector<vector<int>> adj(patience.size());
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // firstly we need to know the shortest path from each node to master
        // node(0) applying bfs for that -> by which we will get shortest
        // distance for each node , from master node
        vector<int> dist(patience.size(), -1);
        queue<int> q;

        // pushing source node
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        // we know that, time taken to get a reply from master will be = 2 *
        // time taken to reach the master node (janey ka time + aney ka time)
        // while this time each node will send another messeges also , with a
        // interval of 0,p,2p,3p.... where p is patience of each
        // node(patience[i]) we need we need to find: Last time the server sends
        // a message before the reply arrives -> largest multiple of p that is <
        // 2d formula for that will be floor((2d-1)/p)*p -1 is because we need
        // multiple of p strictly smaller than 2d

        int maxTime = 0;

        // computing last reply time for every server
        for (int i = 1; i < patience.size(); i++) {

            int d = dist[i];

            int roundTrip = 2 * d; // time for message + reply

            int p = patience[i];

            int lastSent = 0;

            // if patience < 2d, server keeps resending
            if (p < roundTrip) {

                // last resend before reply arrives
                lastSent = ((roundTrip - 1) / p) * p;
            }

            int finalReply = lastSent + roundTrip;
            // network idle time depends on the slowest node , mtlb jiska reply sabse last me ayega
            maxTime = max(maxTime, finalReply);
        }

        // network becomes idle one second after last reply
        return maxTime + 1;
    }
};