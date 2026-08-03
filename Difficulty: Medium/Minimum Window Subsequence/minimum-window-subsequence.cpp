class Solution {
	public:
	string minWindow(string& s1, string& s2) {
		int n = s1.size();
		int m = s2.size();
		
		int start = -1;
		int minLen = INT_MAX;
		
		int i = 0;
		
		while (i < n) {
			int j = 0;
			
			// Forward scan: find a window containing s2 as a subsequence
			while (i < n) {
				if (s1[i] == s2[j])
					j++;
				
				if (j == m)
					break;
				
				i++;
			}
			
			// No more valid windows
			if (i == n)
				break;
			
			// Current window ends at i
			int end = i;
			
			// Backward scan: shrink the window
			j = m - 1;
			while (j >= 0) {
				if (s1[i] == s2[j])
					j--;
				i--;
			}
			
			// i has moved one position before the actual start
			i++;
			int len = end - i + 1;
			
			if (len < minLen) {
				minLen = len;
				start = i;
			}
			
			// Start searching for the next window
			i = i + 1;
		}
		
		if (start == -1)
			return "";
		
		return s1.substr(start, minLen);
	}
};
