class Solution {
	public:
	// Sieve function to get all 4-digit primes
	vector<bool> computeSieve() {
		vector<bool> is_prime(10000, true);
		is_prime[0] = is_prime[1] = false;
		for (int p = 2; p * p < 10000; p++) {
			if (is_prime[p]) {
				for (int i = p * p; i < 10000; i += p) {
					is_prime[i] = false;
				}
			}
		}
		return is_prime;
	}
	
	int minStep(int num1, int num2) {
		if (num1 == num2)
			return 0;
		
		// 1. Get prime flags up to 9999
		vector<bool> is_prime = computeSieve();
		
		// 2. BFS structures
		queue<pair<int, int>> q; // {current_number, steps_taken}
		vector<bool> visited(10000, false);
		
		q.push({num1, 0});
		visited[num1] = true;
		
		while (!q.empty()) {
			int curr = q.front().first;
			int steps = q.front().second;
			q.pop();
			
			if (curr == num2)
				return steps;
			
			string curr_str = to_string(curr);
			
			// Try changing each of the 4 digits
			for (int i = 0; i < 4; i++) {
				char original_char = curr_str[i];
				
				for (char ch = '0'; ch <= '9'; ch++) {
					if (ch == original_char)
						continue;
					if (i == 0 && ch == '0') continue; // No leading zeros for 4-digit numbers
					
					curr_str[i] = ch;
					int next_num = stoi(curr_str);
					
					// If it's a valid 4-digit prime and not visited yet
					if (next_num >= 1000 && is_prime[next_num] && !visited[next_num]) {
						visited[next_num] = true;
						q.push({next_num, steps + 1});
					}
				}
				// Revert back to original character for the next iteration
				curr_str[i] = original_char;
			}
		}
		
		return - 1; // Return -1 if num2 is unreachable
	}
};
