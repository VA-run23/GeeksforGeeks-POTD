// Sum of Beauty of All Substrings

/*
 *    1. The problem asks to find the total beauty of all substrings of a string.
 *    2. Beauty of a substring = (maximum frequency character) - (minimum frequency character).
 *    3. Generate all possible substrings starting from each index i.
 *    4. Maintain a frequency array of 26 characters while extending the substring.
 *    5. For every substring s[i...j], calculate:
 *       - maxFreq = highest non-zero character frequency.
 *       - minFreq = lowest non-zero character frequency.
 *    6. Add (maxFreq - minFreq) to the final answer.
 *    7. Time Complexity: O(n² * 26), Space Complexity: O(26).
 */

class Solution {
  public:
    int beautySum(string &s) {
        // code here
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = n;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};

// Key Points
// 1. Considers every possible substring.
// 2. Maintains character frequencies incrementally.
// 3. Beauty = max frequency - min non-zero frequency.
// 4. Frequency array size remains constant (26).
// 5. Updates answer for each substring independently.
// 6. Avoids recomputing substring frequencies from scratch.
// 7. Runs in O(n²) substrings with O(26) frequency checks each.