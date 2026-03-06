class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            mp[ch] = mp[ch] + 1;
        }

        int v = 0;
        int c = 0;

        for (auto it : mp) {
            char ch = it.first;
            int freq = it.second;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v = max(v, freq);
            } else {
                c = max(c, freq);
            }
        }

        return c + v;
    }
};