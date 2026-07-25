class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> arr;
        int i = 0;
        int j = 0;

        // Lambda function to handle duplicate prevention safely
        auto pushUnique = [&](int val) {
            if (arr.empty() || arr.back() != val) {
                arr.push_back(val);
            }
        };

        // Process elements while both arrays have items remaining
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                pushUnique(a[i]);
                i++;
            } 
            else if (b[j] < a[i]) {
                pushUnique(b[j]);
                j++;
            } 
            else { // a[i] == b[j]
                pushUnique(a[i]);
                i++;
                j++;
            }
        }

        // Clean up remaining elements from array 'a'
        while (i < n) {
            pushUnique(a[i]);
            i++;
        }

        // Clean up remaining elements from array 'b'
        while (j < m) {
            pushUnique(b[j]);
            j++;
        }

        return arr;
    }
};
