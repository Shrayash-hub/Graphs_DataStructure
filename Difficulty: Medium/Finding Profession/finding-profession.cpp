class Solution {
	public:
	bool solve(int x, bool eng) {
		if (x == 1)
			return eng == 1;
		
		if ((x%2) != 0)
			return solve((x + 1)/2, eng);
		else
			return solve((x + 1)/2, !eng);
	}
	string profession(int level, int pos) {
		// code here
		bool is_eng = solve(pos, 1);
		if (is_eng)
			return "Engineer";
		else {
			return "Doctor";
		}
	}
};
