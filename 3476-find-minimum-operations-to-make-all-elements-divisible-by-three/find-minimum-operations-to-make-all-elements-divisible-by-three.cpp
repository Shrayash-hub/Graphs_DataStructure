class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int oper = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i] % 3;
            if(temp<3-temp){
                oper+= temp;
            }
            else{
                oper+=(3-temp);
            }
        }
        return oper;
    }
};