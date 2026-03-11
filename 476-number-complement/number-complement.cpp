class Solution {
public:
    int findComplement(int n) {
        int mask = 1;
        //example:  compliment of 1 0 1 0 , take xor with 1 1 1 1 -> we will get compliment 
        // so first creat 1 1 1 .. upto n -> then take xor with n
        while ((mask & n) != n) {
            mask = mask << 1;
            mask += 1;
        }
        return mask ^ n;
    }
};