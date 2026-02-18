class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = bitset<32>(n).to_string();
        int start = s.find('1');
        s = s.substr(start);
        
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
                if(count>1) return false;
            }
            else{
                count--;
                if(count<0) return false;
            }
        }
        return true;
    }
};