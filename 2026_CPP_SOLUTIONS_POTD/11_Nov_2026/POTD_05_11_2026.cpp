// Minimum Days to Make String Good

/*
 *    1. The problem asks to find the minimum number of days required to make the string good.
 *    2. A string is considered good if no two adjacent characters are equal.
 *    3. Every day, we can replace one character according to the order given in array p.
 *    4. Traverse the string and check for adjacent equal characters.
 *    5. Whenever a conflict s[i] == s[i+1] is found, keep removing characters
 *       in the order specified by p until the conflict disappears.
 *    6. Count the number of removals (days) performed during the process.
 *    7. Time Complexity: O(n), Space Complexity: O(1) excluding modifications to the string.
 */

class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            while (s[i] == s[i + 1] && s[i] != '?') {
                s[p[ans++]] = '?';
            }
        }

        return ans;
    }
};

// Key Points
// 1. Detects adjacent equal characters.
// 2. Characters are removed in the order specified by p.
// 3. Removed characters are marked with '?'.
// 4. Continues removals until each conflict is resolved.
// 5. ans stores the number of days/removals.
// 6. Stops when the string becomes good.
// 7. Uses a greedy simulation approach.