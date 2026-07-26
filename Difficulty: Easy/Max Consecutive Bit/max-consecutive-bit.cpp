class Solution {
	public:
	int solve(vector<int> &arr, int bit) {
		int cnt = 0;
		int maxi = INT_MIN;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == bit) {
				cnt++;
			}
			else {
				cnt = 0;
			}
			maxi = max(maxi, cnt);
		}
		return maxi;
	}
	int maxConsecBits(vector<int> &arr) {
		// code here
		int a = solve(arr, 1);
		int b = solve(arr, 0);
		return max(a, b);
		
	}
};
