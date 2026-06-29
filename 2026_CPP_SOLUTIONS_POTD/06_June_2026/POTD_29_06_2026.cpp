// Maximize Dot Product

/*
 *    1. We want the maximum dot product between subsequences of arrays a and b.
 *    2. Use Dynamic Programming (DP) to solve this efficiently.
 *    3. Define dp[i][j] as the max dot product using first i elements of b and first j elements of a.
 *    4. Base case: if i=0 or j=0, then dp[i][j] = 0 (no elements to pair).
 *    5. Transition: either skip current a[j-1] or pair a[j-1] with b[i-1].
 *    6. Formula: dp[i][j] = max(dp[i][j-1], (a[j-1]*b[i-1]) + dp[i-1][j-1]).
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m).
 */

class Solution {
    public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = b.size();
        int m = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i<dp.size(); i++) {
            for (int j = 0; j<dp[0].size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i<dp.size(); i++) {
            for (int j = i; j<dp[0].size(); j++) {
                dp[i][j] = max(dp[i][j - 1], (b[i - 1]*a[j - 1]) + dp[i - 1][j - 1]);
            }
        }
        return dp[n][m];
    }
};

// Key Points
// 1. DP table stores max dot product for subsequences.
// 2. Base case ensures empty subsequence gives 0.
// 3. Transition considers skipping or pairing elements.
// 4. Formula uses max of two choices.
// 5. Answer is found at dp[n][m].
// 6. Works for ordered subsequences, not necessarily contiguous.
// 7. Complexity is O(n*m) time and space.