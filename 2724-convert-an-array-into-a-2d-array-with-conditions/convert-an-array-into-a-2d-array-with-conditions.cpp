class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<vector<int>> res;
        // nummber of rows is max frequency valey element ki frequency
        // make frequency as index
        for(int num : nums){

            int count = mp[num];

            // if duplicate element comes, create new row
            if(res.size() == count){
                res.push_back(vector<int>());
            }

            res[count].push_back(num);

            mp[num] = count + 1;
        }

        return res;
    }
};