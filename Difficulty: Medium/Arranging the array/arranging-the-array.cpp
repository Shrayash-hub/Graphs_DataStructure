class Solution {
  public:
    void Rearrange(int arr[], int n) {
        // Your code goes here
        vector<int> neg, pos;

        for(int i = 0; i < n; i++){
            if(arr[i] < 0) neg.push_back(arr[i]);
            else pos.push_back(arr[i]);
        }

        int idx = 0;
        for(int x : neg) arr[idx++] = x;
        for(int x : pos) arr[idx++] = x;
    }
};