class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000")) return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int level = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                string curr = q.front();
                q.pop();

                if(curr == target)
                    return level;

                for(int i = 0; i < 4; i++){

                    string up = curr;
                    string down = curr;

                    up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                    down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                    if(!dead.count(up) && !visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }

                    if(!dead.count(down) && !visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};