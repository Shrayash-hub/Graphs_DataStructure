class Solution {
	public:
	int missingNum(vector<int>& arr) {
		// code here
		int n = arr.size() + 1;
		int xor1 = 0, xor2 = 0;
		
		// XOR all array elements
		for (int i = 0; i < n - 1; i++) {
			xor2 ^= arr[i];
		}
		
		// XOR all numbers from 1 to n
		for (int i = 1; i <= n; i++) {
			xor1 ^= i;
		}
		
		// Missing number is the XOR of xor1 and xor2
		return xor1 ^ xor2;
	}
};
