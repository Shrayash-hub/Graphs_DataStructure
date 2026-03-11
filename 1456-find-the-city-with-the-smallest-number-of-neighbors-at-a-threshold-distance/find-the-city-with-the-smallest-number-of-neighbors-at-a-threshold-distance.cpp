class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // distance from node to itself
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // as we have given connected edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // applying floyd Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int min_count = n; // minimum number of reachable cities found so far
        int res = -1;      // city index having the minimum reachable cities

        for (int i = 0; i < n; i++) {

            int count = 0; // counts how many cities are reachable from city i

            for (int j = 0; j < n; j++) {

                // if shortest distance from city i to city j
                // is within the allowed threshold, then city j is reachable
                if (dist[i][j] <= distanceThreshold)
                    count++;
            }

            // we want the city with the smallest reachable cities
            // if two cities have same count, we choose the city with larger
            // index that's why we use <= instead of <
            if (count <= min_count) {
                min_count = count; // update minimum reachable cities
                res = i;           // update result city
            }
        }

        return res; // return the city having smallest reachable neighbors
    }
};