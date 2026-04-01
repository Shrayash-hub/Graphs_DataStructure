class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xori = 0;

        // XOR of all elements
        for (int num : nums) {
            xori ^= num;
        }

        // get rightmost set bit
        unsigned int mask = (unsigned int)xori & (-(unsigned int)xori);

        int a = 0, b = 0;

        // divide into two groups
        for (int num : nums) {
            if ((num & mask) != 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};