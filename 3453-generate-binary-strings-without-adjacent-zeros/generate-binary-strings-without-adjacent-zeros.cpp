class Solution {
public:
    void generate(int n,const string &curr, vector<string>& result) {
        // base case: if length is n, add to result
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }

        // always try adding '1'
        generate(n, curr + "1", result);

        // add '1' only if previous char is not '1'
        if (curr.empty() || curr.back() != '0') {
            generate(n, curr + "0", result);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        generate(n,"",res);
        return res;
    }
};