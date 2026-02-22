class Solution {
public:
    int binaryGap(int n) {
        int maxd = 0;
        int curr = 0;
        bool find_first_one = false;
        while (n > 0) {
            int bit = n % 2;

            if (bit == 1) {
                if (find_first_one) {
                    maxd = max(maxd, curr);
                }
                curr = 1;
                find_first_one = true; 
            } else {
                if (find_first_one) curr++;
            }
            n /= 2;
        }
        
        return maxd;
    }
};