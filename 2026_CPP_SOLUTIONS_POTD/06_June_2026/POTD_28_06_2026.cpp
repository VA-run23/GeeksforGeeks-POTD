// Count Binary Strings with k Adjacent 1's

/*
 *    1. We need to count binary strings of length n.
 *    2. The constraint is exactly k occurrences of consecutive "11".
 *    3. Dynamic Programming is used to track states.
 *    4. dp[i][j][0] represents strings of length i with j pairs ending in 0.
 *    5. dp[i][j][1] represents strings of length i with j pairs ending in 1.
 *    6. Transitions handle adding '0' or '1' while updating counts.
 *    7. Time Complexity: O(n*k), Space Complexity: O(n*k*2).
 */

class Solution {
  public:
    int countStrings(int n, int k) {
        // code here
        const int MOD = 1e9 + 7;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                dp[i][j][0] = ( (long long)dp[i-1][j][0] + dp[i-1][j][1] ) % MOD;

                dp[i][j][1] = dp[i-1][j][0];
                if (j > 0) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1]) % MOD;
                }
            }
        }
        
        return ( (long long)dp[n][k][0] + dp[n][k][1] ) % MOD;
    }
};

// Key Points
// 1. Binary strings are built incrementally using DP.
// 2. State tracks both ending character and count of "11" pairs.
// 3. Transition carefully updates counts when adding '1'.
// 4. Base case initializes strings of length 1.
// 5. Modulo ensures results fit within integer limits.
// 6. Final answer is sum of both ending states at length n.
// 7. Efficient solution avoids brute force enumeration.