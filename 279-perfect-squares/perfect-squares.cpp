class Solution {
public:
    int numSquares(int n) {
        
        // treating every number between 0 se n as a node.
        // from a number x, you can go to:

        // x - 1²
        // x - 2²
        // x - 3²
        // ...  (as long as the result ≥ 0)
        // Each subtraction means we used one perfect square. So the problem becomes: minimum edges to reach 0 starting from n
        // appling bfs to find the shortest path
        queue<int> q;
        
        // visited array to avoid repeated states
        vector<bool> visited(n + 1, false);

        q.push(n);
        visited[n] = true;
        int level = 0; // number of squares used

        while(!q.empty()) {
            int size = q.size();
            level++;   // moving to next level

            for(int i = 0; i < size; i++) {

                int curr = q.front();
                q.pop();

                // try subtracting all squares
                for(int j = 1; j * j <= curr; j++) {

                    int next = curr - j*j;

                    // if we reached 0 -> answer found
                    if(next == 0)
                        return level;

                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return level;
    }
};
