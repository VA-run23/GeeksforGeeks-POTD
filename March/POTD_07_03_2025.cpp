// This function calculates the length of the longest palindromic subsequence in a given string 's'.
// It uses dynamic programming with a 2D table 'dp', where dp[i][j] represents the length of the
// longest palindromic subsequence within the substring s[i..j] of the input string.

// Step 1: Initialize the table such that dp[i][i] = 1, since a single character is always a palindrome.
// Step 2: Iterate over all substring lengths from 2 to n, and for each length, calculate the values of dp[i][j].
// Step 3: If the characters at positions 'i' and 'j' are the same, add 2 to dp[i+1][j-1], otherwise take
// the maximum value between dp[i+1][j] and dp[i][j-1], which represent excluding one character at a time.
// Step 4: After filling the table, the value at dp[0][n-1] contains the length of the longest palindromic subsequence.
// Step 5: The time complexity is O(n^2) due to nested loops, and space complexity is also O(n^2) for the dp table.
// Step 6: Return dp[0][n-1] as the result, which gives the desired length of the palindromic subsequence.

Class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
                }
            }
        }

        return dp[0][n - 1]; 
    }
};