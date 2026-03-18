class Solution {
public:
    void solve(string curr, string s, int i, vector<string>& ans) {
        // if we reached to the end of the string
        if (i == s.length()) {
            ans.push_back(curr); // pushing current string to the ans
            return;
        }

        if (isdigit(s[i])) { // if it is digit , consider it directly
            curr.push_back(s[i]);
            solve(curr, s, i + 1, ans);
        } else { // if it is a alphabet
            // case 1 -> considering lower case
            string c1 = curr;
            c1.push_back(tolower(s[i]));
            solve(c1, s, i + 1, ans);

            // case 2 -> considering upper case
            string c2 = curr;
            c2.push_back(toupper(s[i]));
            solve(c2, s, i + 1, ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve("", s, 0, ans);
        return ans;
    }
};