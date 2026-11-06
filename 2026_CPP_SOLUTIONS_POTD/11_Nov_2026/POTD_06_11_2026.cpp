// Count Balanced Binary Trees of Height h

/*
 *    1. The problem asks to count the number of balanced binary trees of height h.
 *    2. Let dp[h] represent the number of balanced binary trees of height h.
 *    3. A balanced tree of height h can be formed using:
 *       - Left height = h-1 and Right height = h-1.
 *       - Left height = h-1 and Right height = h-2.
 *       - Left height = h-2 and Right height = h-1.
 *    4. Recurrence:
 *       dp[h] = dp[h-1] * dp[h-1]
 *             + 2 * dp[h-1] * dp[h-2]
 *    5. Base cases:
 *       - dp[0] = 1
 *       - dp[1] = 1
 *    6. Use iterative DP with two variables to optimize space.
 *    7. Time Complexity: O(h), Space Complexity: O(1).
 */

class Solution {
  public:
    int countBT(int h) {
        // code here
        long long mod = 1000000007;

        long long a = 1; // dp[0]
        long long b = 1; // dp[1]
        long long c = 1;

        for (int i = 2; i <= h; i++) {
            c = b * ((2 * a) + b) % mod;
            a = b;
            b = c;
        }

        return (int)b;
    }
};

// Key Points
// 1. Uses the balanced binary tree recurrence relation.
// 2. dp[h] depends only on dp[h-1] and dp[h-2].
// 3. Base cases: dp[0] = dp[1] = 1.
// 4. Cases considered: (h-1,h-1), (h-1,h-2), (h-2,h-1).
// 5. Uses modulo 1e9+7 to avoid overflow.
// 6. Space optimized using only three variables.
// 7. Runs in O(h) time with O(1) extra space.