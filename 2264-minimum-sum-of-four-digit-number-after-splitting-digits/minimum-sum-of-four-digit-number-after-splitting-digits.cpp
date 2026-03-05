class Solution {
public:
    int minimumSum(int n) {
        int digits[4];

        for(int i = 0; i < 4; i++){
            digits[i] = n % 10;
            n/=10;
        }

        sort(digits,digits+4);
        int new1 = digits[0] * 10 + digits[2];
        int new2 = digits[1] * 10 + digits[3];

        return new1 + new2;
    }
};