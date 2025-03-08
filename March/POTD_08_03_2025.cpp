/* 
1. The function calculates the longest palindromic substring in the given string `s` using dynamic programming.
2. A 2D vector `dp` is created where `dp[i][j]` is true if the substring `s[i...j]` is a palindrome.
3. Single-character substrings are palindromes by default, so we initialize `dp[i][i]` as true.
4. Two-character palindromic substrings are checked and updated along with `start` and `maxLength`.
5. For substrings longer than 2 characters, we use the smaller substrings' results (`dp[i+1][j-1]`) and compare `s[i]` and `s[j]`.
6. If a longer palindrome is found, `start` and `maxLength` are updated to track its position and length.
7. Finally, the longest palindromic substring is returned using `s.substr(start, maxLength)`.
*/
class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLength = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
    
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                if (maxLength < 2) {
                    start = i;
                    maxLength = 2;
                }
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};