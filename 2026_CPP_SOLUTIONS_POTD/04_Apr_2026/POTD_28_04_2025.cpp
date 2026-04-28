// Longest Repeating Character Replacement

/*
 *    1. We are given a string of uppercase English letters and an integer k.
 *    2. At most k operations can be performed, each changing one character to another.
 *    3. The goal is to find the longest substring that can be transformed into identical characters.
 *    4. We use a sliding window approach to maintain a valid substring.
 *    5. Track the frequency of characters and the count of the most frequent character in the window.
 *    6. If replacements needed exceed k, shrink the window from the left.
 *    7. Time Complexity: O(n), Space Complexity: O(26) = O(1).
 */

class Solution {
public:
    int longestSubstr(string& s, int k) {

        // code here

        vector<int> freq(26, 0);
        int left = 0, maxCount = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);

            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Key Points
// 1. Sliding window ensures efficient traversal without resets.
// 2. Frequency array tracks counts of each character.
// 3. maxCount keeps the highest frequency in the current window.
// 4. Window shrinks when replacements exceed k.
// 5. Answer is updated with the largest valid window size.
// 6. Works for all uppercase English letters (A–Z).
// 7. Optimal solution: O(n) time, O(1) space.