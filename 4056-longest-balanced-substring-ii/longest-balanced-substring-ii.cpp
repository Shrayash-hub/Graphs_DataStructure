

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int ans = 1;                     // at least one character

        // ---------- Case 1: single character runs ----------
        int run = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) ++run;
            else run = 1;
            ans = max(ans, run);
        }

        char ch[3] = {'a', 'b', 'c'};

        // ---------- Helper for case 2 (two distinct chars) ----------
        auto process_two = [&](int start, int end, char x, char y) {
            int len = end - start + 1;
            unordered_map<int, int> first_occ;
            first_occ[0] = -1;           // sum 0 before the segment
            int sum = 0;
            for (int i = 0; i < len; ++i) {
                char c = s[start + i];
                if (c == x) ++sum;
                else if (c == y) --sum; // c must be x or y (no third char)
                auto it = first_occ.find(sum);
                if (it != first_occ.end()) {
                    ans = max(ans, i - it->second);
                } else {
                    first_occ[sum] = i;
                }
            }
        };

        // ---------- Case 2: three pairs ----------
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                char x = ch[i];
                char y = ch[j];
                char z = ch[3 - i - j]; // the third character
                int pos = 0;
                while (pos < n) {
                    if (s[pos] == z) {
                        ++pos;
                        continue;
                    }
                    int start = pos;
                    while (pos < n && s[pos] != z) ++pos;
                    // segment [start, pos-1] contains no z
                    if (start <= pos-1) {
                        process_two(start, pos-1, x, y);
                    }
                }
            }
        }

        // ---------- Case 3: all three characters ----------
        {
            map<pair<int,int>, int> earliest;
            earliest[{0, 0}] = -1;       // before first character
            int ca = 0, cb = 0, cc = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a') ++ca;
                else if (s[i] == 'b') ++cb;
                else ++cc;               // 'c'
                int d1 = cb - ca;
                int d2 = cc - ca;
                auto key = make_pair(d1, d2);
                auto it = earliest.find(key);
                if (it != earliest.end()) {
                    ans = max(ans, i - it->second);
                } else {
                    earliest[key] = i;
                }
            }
        }

        return ans;
    }
};