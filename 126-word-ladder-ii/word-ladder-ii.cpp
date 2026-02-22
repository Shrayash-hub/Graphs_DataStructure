class Solution {
public:
    void dfs(string word, string beginWord, unordered_map<string, int>& mpp,
             vector<vector<string>>& ans, vector<string>& seq) {
        // base case -> when we reached beginWord
        if (word == beginWord) {
            // reverse because we are backtracking from endWord → beginWord
            reverse(seq.begin(), seq.end());

            ans.push_back(seq);

            // reverse back to original for further backtracking
            reverse(seq.begin(), seq.end());

            return;
        }

        int steps = mpp[word];

        // try changing each character
        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                // check if word exists in map and is one level before
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    // add to sequence
                    seq.push_back(word);

                    // recursive call
                    dfs(word, beginWord, mpp, ans, seq);

                    // backtrack
                    seq.pop_back();
                }
            }

            // restore original character
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        // convert wordList to set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // queue for BFS
        queue<string> q;

        // map to store level of each word
        unordered_map<string, int> mpp;

        // start BFS from beginWord
        q.push(beginWord);

        // remove beginWord from set
        st.erase(beginWord);

        int level = 1;

        // mark level of beginWord
        mpp[beginWord] = level;

        // BFS to fill level map
        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop(); 

                for (int j = 0; j < word.size(); j++) {

                    char original = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[j] = ch;

                        // if word exists in set
                        if (st.find(word) != st.end()) {

                            q.push(word);

                            // store level of word
                            mpp[word] = level + 1; 

                            st.erase(word);
                        }
                    }

                    // restore original character
                    word[j] = original;
                }
            }

            level++;
        }

        vector<vector<string>> ans;

        // check if endWord reachable
        if (mpp.find(endWord) != mpp.end()) {

            vector<string> seq;

            seq.push_back(endWord);

            // start DFS backtracking
            dfs(endWord, beginWord, mpp, ans, seq);
        }

        return ans;
    }
};