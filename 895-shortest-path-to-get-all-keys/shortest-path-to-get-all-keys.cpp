class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // firstly lets find the total number of keys and the coordinated of
        // starting cell
        int totalKeys = 0;
        int startRow;
        int startClm;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '@') {
                    startRow = i;
                    startClm = j;
                }
                // if we found a key
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }
        // as minimum path nikalna h toh bfs hi lagega

        // normal visited array is not going to work here , because the same
        // cell can represent different states depending on which keys we have
        // collected

        // so we will track visited[row][col][keyMask] -> where key mask is the
        // state which is going to tell that , konsi konsi key h hmarey
        // pass(colleted keys)

        // keyMask should be maximum 1111..number of keys -> 2^totalKeys
        // and 1111.. in decimal = 2^totalKeys-1
        int final_keyStat = (1 << totalKeys) - 1;
        int visited[grid.size()][grid[0].size()][final_keyStat+1];
        memset(visited, 0, sizeof(visited)); // initalizing vis array

        queue<pair<int, pair<int, int>>> q; // {current_key_state,{i,j}}
        q.push({0, {startRow, startClm}});
        visited[startRow][startClm][0] = 1;

        // bfs lagatey h ab
        int moves = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int sz = q.size();   

            while (sz--) {

                auto temp = q.front();
                q.pop();
                int Curr_key_state = temp.first;
                int i = temp.second.first;
                int j = temp.second.second;

                // if we found all the keys
                if (Curr_key_state == final_keyStat) {
                    return moves;
                }

                // lets explore all the nbr
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    // checking boundary conditions
                    if (ni >= 0 && nj >= 0 && ni < grid.size() &&
                        nj < grid[0].size() && grid[ni][nj] != '#') {

                        char cell = grid[ni][nj];
                        int newMask = Curr_key_state;
                        // this cell can be a empty cell

                        // key found
                        if (cell >= 'a' && cell <= 'f') {
                            // update the newMask to store this key
                            // suppose b(0010) mila and a(0001) already tha
                            // dono store krney k liye 0010 | 0001 = 0011
                            newMask |= (1 << (cell - 'a'));
                        }

                        // lock
                        if (cell >= 'A' && cell <= 'F') {
                            // if key is not present for this lock , continue
                            
                            // suppose currMask is 0010(b key) and found B lock
                            // 0010 & 0010 = 0010 != 0 (key found)
                            if ((Curr_key_state & (1 << (cell-'A'))) == 0)
                                continue;
                        }

                        // if key found or lock h or empty cell h toh mark visited and push the current cell into the queue
                        if (!visited[ni][nj][newMask]) {

                            visited[ni][nj][newMask] = 1;
                            q.push({newMask,{ni,nj}});
                        }
                    }
                }
            }

            moves++;   // increasing moves after finishing a level
        }
        return -1;
    }
};
