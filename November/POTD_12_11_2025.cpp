/*
   1. The function wildCard checks if a given pattern (pat) matches a text (txt) using wildcard rules: 
      '?' matches any single character, '*' matches any sequence (including empty).
   2. It uses dynamic programming with two boolean arrays (prev and curr) to store matching states 
      for each prefix of the text against the current prefix of the pattern.
   3. prev[0] = true initializes the base case, meaning an empty pattern matches an empty text.
   4. For each character in the pattern, curr[0] is set true only if all characters so far are '*', 
      since '*' can match an empty sequence.
   5. For each character in the text, the code checks:
      - If pat[i-1] == txt[j-1] or pat[i-1] == '?', then curr[j] = prev[j-1].
      - If pat[i-1] == '*', then curr[j] = prev[j] (skip '*') || curr[j-1] (match one more char) || prev[j-1].
      - Otherwise, curr[j] = false.
   6. After processing each pattern character, prev is updated to curr for the next iteration.
   7. Finally, prev[m] gives the result: true if the entire pattern matches the entire text, false otherwise.

   Time Complexity: O(n * m), where n = pattern length and m = text length (nested loops).
   Space Complexity: O(m), since only two arrays of size (m+1) are maintained.
*/

class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = pat.size();
        int m = txt.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for (int i = 1; i <= n; i++) {
            bool allStars = true;
            for (int k = 1; k <= i; k++) {
                if (pat[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }
            curr[0] = allStars;

            for (int j = 1; j <= m; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (pat[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1] || prev[j - 1];
                } else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};