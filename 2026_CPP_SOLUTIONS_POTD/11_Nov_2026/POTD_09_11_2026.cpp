// Count Characters Appearing in Exactly K Groups

/*
 *    1. The problem asks to count characters that appear in exactly k consecutive groups.
 *    2. A group is formed by one or more consecutive occurrences of the same character.
 *    3. Traverse the string and count only the start of each new group.
 *    4. Use a hash map to store the number of groups formed by each character.
 *    5. If s[i] != s[i-1], a new group starts and its frequency is incremented.
 *    6. After processing the string, count characters whose group frequency equals k.
 *    7. Time Complexity: O(n), Space Complexity: O(1) since only lowercase characters are stored.
 */

class Solution {
	public:
	int getCount(string &s, int k) {
		// code here
		int n = s.size(), i = 1;
		unordered_map<char, int> mp;

		mp[s[0]]++;

		while (i < n) {
			if (s[i] != s[i - 1])
				mp[s[i]]++;

			i++;
		}

		int ct = 0;

		for (auto &it : mp) {
			if (it.second == k)
				ct++;
		}

		return ct;
	}
};

// Key Points
// 1. Counts occurrences of character groups, not individual characters.
// 2. Consecutive equal characters belong to the same group.
// 3. A new group starts when current character differs from previous.
// 4. Hash map stores group count for each character.
// 5. Final answer counts characters with exactly k groups.
// 6. Single traversal of the string is sufficient.
// 7. Runs in O(n) time with O(1) extra space.