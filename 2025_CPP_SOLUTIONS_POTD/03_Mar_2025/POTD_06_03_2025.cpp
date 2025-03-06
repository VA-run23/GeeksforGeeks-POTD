/* 
1. Define the function `lcs` that calculates the length of the longest common subsequence (LCS) between two strings `s1` and `s2`.
2. Initialize a 2D vector `dp` of size `(m+1) x (n+1)` with zeros, where `m` and `n` are the lengths of `s1` and `s2`, respectively.
3. Use nested loops to iterate through each character of both strings.
4. If the characters match (`s1[i-1] == s2[j-1]`), update `dp[i][j]` with `1 + dp[i-1][j-1]` (diagonal value, representing extending the LCS).
5. If the characters don't match, update `dp[i][j]` with the maximum of `dp[i-1][j]` (top value) or `dp[i][j-1]` (left value).
6. The final LCS length is stored in `dp[m][n]`, which represents the LCS length for the entire strings.
7. Return `dp[m][n]` as the result, which is the length of the longest common subsequence.
*/
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};