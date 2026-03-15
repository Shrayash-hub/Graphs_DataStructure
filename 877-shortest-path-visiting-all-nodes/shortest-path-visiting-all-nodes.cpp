class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // as we need to find the shortest path , we will be applying bfs from
        // each node -> as we can get different path sizes , if we start from
        // the diffrent nodes

        // we are going to save the nodes that are visited , in form of bitMask
        // if we visited the ith node , ith bit from the last should be set 1
        queue<pair<int, int>> q;               // {node,bitMask}
        set<pair<int, int>> visited; // {node,bitMask}

        // bfs from every node
        for (int i = 0; i < graph.size(); i++) {
            int bitMask = 1 << i;
            q.push({i, bitMask});
            visited.insert({i, bitMask});
        }

        // if we visited all the nodes , bfs should stop
        // target when currentMask will be 1111 = 2^n - 1
        int n = graph.size();
        int allNodeVisited = (1 << n) - 1;

        // lets start bfs
        int path = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int currMask = temp.second;

                // if all the nodes are visited
                if (currMask == allNodeVisited)
                    return path;

                // lets explore all the nei
                for (auto& nei : graph[node]) {
                    // suppose currMask 0100 h , means 2 node visited and nei 2 ka 1 h toh 1 visited ka bitMask 0010 , so dono visited ko save krna h , toh 0110 hona chahiye -> vo 0100 aur 0010 k OR se a jayega
                    int newMask = currMask | (1 << nei);

                    if (!visited.count({nei, newMask})) {
                        q.push({nei, newMask});
                        visited.insert({nei, newMask});
                    }
                }
            }
            path++;
        }
        return -1;
    }
};