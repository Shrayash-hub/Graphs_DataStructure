class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        // lets build adjacency list
        vector<vector<int>> adj(n + 1);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // d1[i] -> shortest time to reach node i
        // d2[i] -> second shortest time to reach node i
        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);

        // storing {currentTime, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // starting from node 1 at time 0
        pq.push({0,1});
        d1[1] = 0;

        while(!pq.empty()){

            auto [timePassed, node] = pq.top();
            pq.pop();

            // if we reached destination and already have second minimum
            if(node == n && d2[n] != INT_MAX)
                return d2[n];

            // Checking for the traffic signal
            int div = timePassed / change;

            // if red signal lets wait until it is green
            if(div % 2 == 1){
                timePassed = change * (div + 1);
            }

            // exploring all the nbr
            for(auto &nbr : adj[node]){
                int arrival = timePassed + time;

                // found new shortest time
                if(arrival < d1[nbr]){
                    d2[nbr] = d1[nbr];
                    d1[nbr] = arrival;
                    pq.push({arrival, nbr});
                }

                // found second shortest time
                else if(arrival > d1[nbr] && arrival < d2[nbr]){
                    d2[nbr] = arrival;
                    pq.push({arrival, nbr});
                }
            }
        }
        return -1;
    }
};
