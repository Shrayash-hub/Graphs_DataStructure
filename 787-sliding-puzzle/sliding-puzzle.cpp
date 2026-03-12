class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        // converting board into string as its easy to store string into queue/map.set
        string start = "";
        for(auto &row : board){
            for(auto &cell : row){
                start += to_string(cell);
            }
        }
        
        // target state in string
        string target = "123450";

        // adjacency list which is going to represent valid swaps for each index(0 valey only)
        vector<vector<int>> moves = {
            {1,3},     // when '0' is at index 0
            {0,2,4},   // when '0' is at index 1
            {1,5},     // when '0' is at index 2
            {0,4},     // when '0' is at index 3
            {1,3,5},   // when '0' is at index 4
            {2,4}      // when '0' is at index 5
        };

        // applying bfs to find the minimum number of steps
        queue<string> q;

        // visited states taki infinite loop me na fasey as cycles bhi ban skti h
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int steps = 0;

        while(!q.empty()){

            int size = q.size();

            // processing current bfs level -> yha level size nikalney vala code 
            // lagega bfs ka , as there can be many states at single level
            while(size--){
                string curr = q.front();
                q.pop();

                // target state mil gyi return steps
                if(curr == target)
                    return steps;

                // finding  index of zero in string
                int zeroPos = curr.find('0');

                // trying all possible swaps usng adj list
                for(int nei : moves[zeroPos]){
                    string next = curr;

                    // swap zero with nei tile
                    swap(next[zeroPos], next[nei]);

                    // if new state not visited
                    if(!visited.count(next)){
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // increment the move count after each level of processing
            steps++;
        }

        // if we never reached target 
        return -1;
    }
};