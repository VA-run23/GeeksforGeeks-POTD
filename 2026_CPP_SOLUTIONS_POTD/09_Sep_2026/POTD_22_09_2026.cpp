// Find Longest Word in Dictionary with Removals

/*
 *    1. The problem asks to find the longest word in dictionary `d` that can be formed by deleting characters from string `s`.
 *    2. Approach:
 *       - Precompute "next occurrence" arrays for each position in `s`.
 *       - For each dictionary word, check if it can be formed as a subsequence of `s`.
 *    3. Steps:
 *       - Build `vec[i]` → stores next occurrence index for each character starting from position i.
 *       - For each word in dictionary:
 *         - Traverse through characters using `vec` to jump to next occurrence.
 *         - If traversal succeeds, word is a valid subsequence.
 *    4. Track longest valid word:
 *       - If multiple words have same length, return lexicographically smallest.
 *    5. Time Complexity: O(|s|*26 + |d|*|word|), Space Complexity: O(|s|*26).
 */

class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        vector<vector<int>> vec(s.size());
        vector<int> next(26, -1);

        // Build next occurrence table
        vec[s.size() - 1] = next;
        map<char, int> mp;
        mp[s[s.size() - 1]] = s.size() - 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            next[s[i + 1] - 'a'] = i + 1;
            vec[i] = next;
            mp[s[i]] = i;
        }

        vector<string> ans;
        int maxi = 0;

        // Check each dictionary word
        for (int i = 0; i < d.size(); i++) {
            if (mp.find(d[i][0]) == mp.end()) continue;

            int pos = mp[d[i][0]];
            int j = 1;

            for (; j < d[i].size(); j++) {
                pos = vec[pos][d[i][j] - 'a'];
                if (pos == -1) break;
            }

            if (j == d[i].size()) {
                ans.push_back(d[i]);
                maxi = max(maxi, (int)d[i].size());
            }
        }

        sort(ans.begin(), ans.end());
        for (auto &it : ans) {
            if ((int)it.size() == maxi)
                return it;
        }
        return "";
    }
};

// Key Points
// 1. Precompute next occurrence table for efficient subsequence checks.
// 2. Each dictionary word checked against `s` using jumps.
// 3. Track longest valid subsequence word.
// 4. Lexicographically smallest chosen if tie.
// 5. Efficient O(|s|*26 + |d|*|word|) solution.
// 6. Uses DP-style preprocessing for subsequence validation.
// 7. Elegant approach to subsequence matching problem.