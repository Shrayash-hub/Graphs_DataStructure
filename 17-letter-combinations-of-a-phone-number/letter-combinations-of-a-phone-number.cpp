class Solution {
public:
    void solve(int index,string &curr,string digits,vector<string> &ans,string mpp[]){
        if(index==digits.size()){
            ans.push_back(curr);
            return;
        }
        string str = mpp[digits[index]-'0'];
        for(int i=0;i<str.size();i++){
            curr.push_back(str[i]);
            solve(index+1,curr,digits,ans,mpp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mpp[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr ="";
        solve(0,curr,digits,ans,mpp);
        return ans;
    }
};