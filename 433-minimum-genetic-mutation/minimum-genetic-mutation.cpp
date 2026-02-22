class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(), bank.end());

        // if endGene not in bank, impossible
        if (!st.count(endGene))
            return -1;

        queue<string> q;
        q.push(startGene);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                // if reached target
                if (word == endGene)
                    return level;

                // try changing each position
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];

                    for (char ch : {'A', 'C', 'G', 'T'}) {
                        word[j] = ch;

                        // if word is in set -> valid
                        if (st.count(word)) {
                            q.push(word);
                            st.erase(word); // mark visited
                        }
                    }
                    word[j] = original; // restore the original word
                }
            }
            level++;
        }
        return -1;
    }
};