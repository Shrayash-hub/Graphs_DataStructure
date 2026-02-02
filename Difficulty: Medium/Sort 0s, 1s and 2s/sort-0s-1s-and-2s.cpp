class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int start = 0;
        int mid = 0;
        int end = arr.size()-1;
        
        while(mid<=end){
            if(arr[mid]==0){
                swap(arr[mid],arr[start]);
                mid++;
                start++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[end]);
                end--;
            }
        }
    }
};