class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st;
        vector<int> result(friends.size());

        for(int num : friends){
            st.insert(num);
        }

        int j = 0;
        for(int i = 0; i < order.size(); i++){
            if(st.count(order[i])){
                result[j] = order[i];
                j++;
            }
        }

        return result;
    }
};