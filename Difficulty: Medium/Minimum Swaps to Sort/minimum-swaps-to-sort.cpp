class Solution {
	public:
	int minSwaps(vector<int>& arr) {
		unordered_map<int, int> mpp;
		vector<int> sorted = arr;
		sort(sorted.begin(), sorted.end());
		
		// current position of every element
		for (int i = 0; i < arr.size(); i++) {
			mpp[arr[i]] = i;
		}
		
		int cnt = 0;
		
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == sorted[i])
				continue;
			cnt++;
			
			int currPos = mpp[sorted[i]];
			
			// update positions in map
			mpp[arr[i]] = currPos;
			mpp[sorted[i]] = i;
			
			swap(arr[i], arr[currPos]);
		}
		return cnt;
	}
};
