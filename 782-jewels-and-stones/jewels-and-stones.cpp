class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_set<char> st;

        for(char ch : jewels){
            st.insert(ch);
        }

        for(int i = 0; i < stones.size(); i++){
            if(st.count(stones[i])){
                count++;
            }
        }

        return count;
    }
};