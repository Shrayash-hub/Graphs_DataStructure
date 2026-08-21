class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // visited set , if string is not present in this set , that means its already visited
        unordered_set<string> st;
        
        for(auto it: words){
            st.insert(it);
        }
        
        queue<string> q;
        q.push(s);
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string temp = q.front();
                if(temp == e) return level;
                q.pop();
                for(int i = 0 ; i < temp.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        string original = temp;
                        temp[i] = c;
                        if(st.count(temp)){
                            q.push(temp);
                            st.erase(temp);
                        }
                        temp = original;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};