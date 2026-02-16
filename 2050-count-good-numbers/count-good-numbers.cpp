class Solution {
public:
    const int M = 1e9 + 7;

    long long findPower(long long a, long long b) {
        // Base case
        if (b == 0) {
            return 1;
        }

        // Recursive call for half power
        long long half = findPower(a, b / 2);

        // Square the half result
        long long result = (half * half) % M;

        // if exponent is odd, multiply one more time by base
        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        return (long long)findPower(5, evenPositions) *
               findPower(4, oddPositions) % M;
    }
};
