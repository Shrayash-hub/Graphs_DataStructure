class Solution {
public:
    int longestCycle(vector<int>& edges) {

        // number of nodes
        int n = edges.size();

        
        vector<int> indegree(n, 0);

        
        for (int i = 0; i < n; i++) {

            // if node has outgoing edge
            if (edges[i] != -1)

                
                indegree[edges[i]]++;
        }

        
        queue<int> q;

        // push all nodes with indegree = 0
        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0)
                q.push(i);
        }

        // to mark nodes removed by topo sort
        vector<bool> removed(n, false);

        // removing non cycle nodes
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // mark node removed
            removed[node] = true;

            // next node
            int next = edges[node];

            // if edge exists
            if (next != -1) {

                // reduce indegree
                indegree[next]--;

                // if becomes 0 push to queue
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        int ans = -1;

        // now only cycles remain
        for (int i = 0; i < n; i++) {

            // if node not removed
            if (!removed[i]) {

                int curr = i;
                int len = 0;

                // traverse cycle
                while (!removed[curr]) {

                    removed[curr] = true;

                    curr = edges[curr];

                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};