class Solution {
public:
    bool checkZeroOnes(string s) {
        int max0 = 0;
        int max1 = 0;

        int count0 = 0;
        int count1 = 0;

        for (auto ch : s) {

            if (ch == '0') {
                count0++;
                count1 = 0;
                max0 = max0 < count0 ? count0 : max0;
            } else {
                count1++;
                count0 = 0;
                max1 = max1 < count1 ? count1 : max1;
            }
        }

        return max1 > max0;
    }
};