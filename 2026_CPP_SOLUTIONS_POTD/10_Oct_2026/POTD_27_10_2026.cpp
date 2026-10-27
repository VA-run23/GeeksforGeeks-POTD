/*
1. The function calculates the maximum weight possible from the string using dynamic programming.
2. next1 stores the result for the next position, while next2 stores the result for two positions ahead.
3. curr stores the maximum weight calculated for the current position.
4. The loop traverses the string backward, starting from the second-last character.
5. If adjacent characters are equal, it compares the options 1 + next1 and 3 + next2.
6. If adjacent characters differ, it calculates the weight as 4 + next2.
7. After each iteration, the DP variables are updated, and the final result is returned.
*/
class Solution {
	public:
	int getMaxWeight(string &s) {
		// code here
		int n = s.size();

		int next1 = 1;
		int next2 = 0;
		int curr = 1;

		for (int i = n - 2; i >= 0; i--) {

			if (s[i] == s[i + 1])
				curr = max(1 + next1, 3 + next2);
			else
				curr = 4 + next2;

			next2 = next1;
			next1 = curr;
		}

		return curr;
	}
};

/*
7 Key Points:
1. Uses dynamic programming to calculate the maximum possible weight.
2. Processes the string from right to left.
3. next1 represents the DP value for the next position.
4. next2 represents the DP value for two positions ahead.
5. Equal adjacent characters allow two choices: 1 + next1 or 3 + next2.
6. Different adjacent characters contribute 4 + next2.
7. Uses O(n) time and O(1) extra space.
*/