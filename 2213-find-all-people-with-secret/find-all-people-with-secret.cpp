class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        // adjacency list: person -> (neighbor, meeting time)
        vector<vector<pair<int, int>>> adj(n);

        // build graph
        for (auto& edge : meetings) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // min heap -> (time, person)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // vis[i] = earliest time person i learns secret
        vector<int> vis(n, INT_MAX);

        // two sources know secret at time 0
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vis[0] = 0;
        vis[firstPerson] = 0;

        // dijkstra traversal
        while (!pq.empty()) {

            auto temp = pq.top();
            pq.pop();

            int node = temp.second;
            int currTime = temp.first;

            if(currTime > vis[node]) continue;
            
            // explore all meetings of this person
            for (auto nei : adj[node]) {

                int next = nei.first;
                int time = nei.second;

                // secret can spread only if meeting occurs
                // after the person knows the secret
                // and if we found earlier arrival time
                if (currTime <= time && time < vis[next]) {

                    vis[next] = time;          // update earliest time
                    pq.push({time, next});     // continue spreading
                }
            }
        }

        // collect all people who learned the secret
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};
