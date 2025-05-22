/*
    1. Initialize a 2D DP table dp of size n x n with all values set to 0.
    2. Iterate over the string from the end to the beginning to ensure subproblems are solved first.
    3. Set dp[i][i] = 1 because a single character is always a palindrome of length 1.
    4. If characters s[i] and s[j] match, extend the palindrome and add 2 to the value from dp[i+1][j-1].
    5. Otherwise, take the maximum of removing either s[i] or s[j] to maintain the longest palindromic subsequence.
    6. After filling the DP table, dp[0][n-1] holds the length of the longest palindromic subsequence.
    7. The minimum deletions required to make s a palindrome is n - dp[0][n-1].
*/


class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return n - dp[0][n - 1]; 
    }
};
