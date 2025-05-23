/* 
    This function computes the minimum number of deletions needed to make a string a palindrome.
    1. We use dynamic programming (DP), where dp[i][j] stores the longest palindromic subsequence (LPS) between indices i and j.
    2. Base case: A single character is a palindrome, so dp[i][i] = 1.
    3. We iterate over all pairs (i, j), filling the DP table based on character matches.
    4. If characters match (s[i] == s[j]), we extend LPS by 2 using dp[i+1][j-1].
    5. Otherwise, we take the maximum value from neighboring subsequences (dp[i+1][j] or dp[i][j-1]).
    6. The final answer is derived from dp[0][n-1], representing the longest palindromic subsequence in the entire string.
    7. The minimum deletions required = total length (n) - longest palindromic subsequence length.
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
