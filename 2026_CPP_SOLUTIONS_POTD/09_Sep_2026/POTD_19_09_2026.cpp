// Minimum Cost to Make Two Strings Identical

/*
 *    1. The problem asks to make two strings identical by deleting characters.
 *    2. Each deletion has a cost: costS1 for deleting from s1, costS2 for deleting from s2.
 *    3. Key observation: Keep the longest common subsequence (LCS) of s1 and s2.
 *    4. Characters not in LCS must be deleted.
 *    5. Compute LCS length using DP:
 *       - dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1].
 *       - If characters match → dp[i][j] = 1 + dp[i-1][j-1].
 *       - Else → dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
 *    6. Cost = (len(s1) - LCS) * costS1 + (len(s2) - LCS) * costS2.
 *    7. Time Complexity: O(m * n), Space Complexity: O(m * n).
 */

class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Step 1: Compute LCS
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int lcsLen = dp[m][n];
        
        // Step 2: Calculate cost
        int r1 = (m - lcsLen) * costS1;
        int r2 = (n - lcsLen) * costS2;
        
        return r1 + r2;
    }
};

// Key Points
// 1. LCS determines characters to keep.
// 2. Remaining characters must be deleted.
// 3. Deletion cost depends on string source.
// 4. Formula: (len(s1)-LCS)*costS1 + (len(s2)-LCS)*costS2.
// 5. DP table computes LCS in O(m*n).
// 6. Efficient solution with clear logic.
// 7. Elegant use of LCS for cost minimization.