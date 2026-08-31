// Minimum Cost for n Characters

/*
 *    1. The problem asks to minimize the cost of producing n characters.
 *    2. Three operations are allowed:
 *       - Insert (cost = i)
 *       - Delete (cost = d)
 *       - Copy (cost = c)
 *    3. Use recursion + memoization (DP) to explore possibilities.
 *    4. Base cases:
 *       - n == 0 → cost = 0
 *       - n == 1 → cost = i
 *    5. Recurrence:
 *       - ans = i * n (all insertions)
 *       - If n is even → ans = min(ans, c + solve(n/2))
 *       - If n is odd → consider both (n+1)/2 and (n-1)/2 with delete/insert adjustments.
 *    6. Memoize results in dp[n] to avoid recomputation.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int solve(int n, int i, int d, int c, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return i;

        if (dp[n] != -1) return dp[n];

        int ans = i * n;

        if (n % 2 == 0) {
            ans = min(ans, c + solve(n/2, i, d, c, dp));
        } else {
            ans = min(ans, d + c + solve((n+1)/2, i, d, c, dp));
            ans = min(ans, i + c + solve((n-1)/2, i, d, c, dp));
        }

        return dp[n] = ans;
    }

    int minCost(int n, int i, int d, int c) {
        vector<int> dp(n+1, -1);
        return solve(n, i, d, c, dp);
    }
};

// Key Points
// 1. Recursion explores all possible ways to reach n.
// 2. Base cases handle n=0 and n=1 directly.
// 3. Insert cost = i * n is default solution.
// 4. Even n → copy operation reduces cost.
// 5. Odd n → handle via delete or insert adjustments.
// 6. Memoization ensures O(n) efficiency.
// 7. Runs in O(n) time with O(n) space.