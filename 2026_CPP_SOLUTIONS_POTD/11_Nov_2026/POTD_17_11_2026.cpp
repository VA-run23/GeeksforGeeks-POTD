// Check for Balanced x-y Pattern

/*
 *    1. The problem asks to determine whether the string follows a valid x-y pattern.
 *    2. Let xCount be the number of 'x' characters encountered so far.
 *    3. Let yCount be the number of 'y' characters encountered so far.
 *    4. Traverse the string from left to right and update the counts.
 *    5. At every position, ensure xCount >= yCount.
 *       - If yCount becomes greater, the pattern is invalid.
 *    6. After processing the entire string, the total counts of x and y must be equal.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
	public:
	bool findPattern(string& s) {
		// code here

		int x = 0, y = 0;

		for (auto ch : s) {
			ch == 'x' ? x++ : y++;

			if (x < y)
				return false;
		}

		return x == y;
	}
};

// Key Points
// 1. Tracks counts of 'x' and 'y' while traversing.
// 2. Every prefix must satisfy xCount >= yCount.
// 3. If yCount exceeds xCount, the pattern is invalid.
// 4. Similar to checking balanced parentheses.
// 5. Final counts of x and y must be equal.
// 6. Single traversal of the string is sufficient.
// 7. Runs in O(n) time with O(1) extra space.