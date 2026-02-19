class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second!=0){
                count+= ((it.second)*(it.second-1))/2;
            }
        }
        return count;
    }
};