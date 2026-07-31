class Solution {
	public:
	int longestKSubstr(string &s, int k) {
		// code here
		int n = s.size();
		int left = 0;
		int right = 0;
		int maxLen = 0;
		unordered_map<char, int> mpp;
		while (right < n) {
			mpp[s[right]]++;
			if (mpp.size() > k) {
				mpp[s[left]]--;
				if (mpp[s[left]] == 0) {
					mpp.erase(s[left]);
				}
				left++;
			}
			maxLen = max(maxLen, right - left + 1);
			right++;
		}
		if(mpp.size() < k) return -1;
		return maxLen;
	}
};
