class Solution {
public:
    int minimumNumbers(int sum, int k) {

        // intuition (simple thinking):
        // Hume kuch numbers lene hain jinka last digit k ho.
        // Example: agar k = 3 hai to possible numbers ho sakte hain
        // 3, 13, 23, 33, 43, ... (bas last digit 3 hona chahiye)
        //
        // Ab maan lo hum i numbers lete hain.
        // To un sabka total sum ka last digit depend karega (i * k) % 10 par.
        //
        // Example:
        // k = 3
        // i = 1 → last digit = (1*3)%10 = 3
        // i = 2 → last digit = (2*3)%10 = 6
        // i = 3 → last digit = (3*3)%10 = 9
        // i = 4 → last digit = (4*3)%10 = 2
        //
        // Agar (i*k)%10 == sum%10 ho gaya,
        // to iska matlab hai ki hum aise numbers choose kar sakte hain
        // jinka total sum ka last digit sum ke last digit jaisa ho.
        //
        // Dusri condition: i*k <= sum
        // Kyunki minimum case me agar hum i numbers lete hain,
        // to sabse chhota possible sum tab hoga jab sab numbers = k ho.
        // Agar wo bhi sum se bada ho gaya, to impossible hai.
        //
        // Bas hume minimum i chahiye.
        //
        //  observation:
        // Last digit ka pattern max 10 steps me repeat ho jata hai,
        // isliye i = 1 se 10 tak check karna enough hai.

        if (sum == 0)
            return 0;

        for (int i = 1; i <= 10; i++) {
            if ((i * k) % 10 == sum % 10 && i * k <= sum) {
                return i;
            }
        }

        return -1;
    }
};