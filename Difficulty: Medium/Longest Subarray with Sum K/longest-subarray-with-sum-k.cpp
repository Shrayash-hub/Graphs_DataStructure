class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		// code here
		unordered_map<long long, int> mpp;
		int sum = 0;
		int maxi = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if (sum == k) {
				maxi = max(maxi, i + 1);
			}
			int rem = sum - k;
			if (mpp.find(rem) != mpp.end()) {
				int len = i - mpp[rem];
				maxi = max(maxi, len);
			}
			if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
		}
		return maxi;
	}
};
