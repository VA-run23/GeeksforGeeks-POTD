// Minimum Cost Pizza Selection

/*
 *    1. Problem: You want exactly x slices of pizza.
 *       - Small pizza gives s slices at cost cs.
 *       - Medium pizza gives m slices at cost cm.
 *       - Large pizza gives l slices at cost cl.
 *    2. Goal: Minimize total cost to get at least x slices.
 *    3. Approach:
 *       - Use recursion + memoization (DP).
 *       - helper(x) = minimum cost to get x slices.
 *       - Transition:
 *         helper(x) = min(
 *             helper(x - s) + cs,
 *             helper(x - m) + cm,
 *             helper(x - l) + cl
 *         )
 *       - Base case: if x <= 0 → 0 (no cost needed).
 *    4. Answer = helper(x).
 *    5. Time Complexity: O(x), Space Complexity: O(x).
 */

class Solution {
  public:
    int helper(int x, int s, int m, int l, int cs, int cm, int cl, vector<int>& dp) {
        if (x <= 0) return 0; // base case
        if (dp[x] != -1) return dp[x];

        dp[x] = min({
            helper(x - s, s, m, l, cs, cm, cl, dp) + cs,
            helper(x - m, s, m, l, cs, cm, cl, dp) + cm,
            helper(x - l, s, m, l, cs, cm, cl, dp) + cl
        });

        return dp[x];
    }

    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        vector<int> dp(x + 1, -1);
        return helper(x, s, m, l, cs, cm, cl, dp);
    }
};

// Key Points
// 1. Recursive DP ensures optimal cost calculation.
// 2. Base case handles overshoot (x <= 0).
// 3. Memoization avoids repeated calculations.
// 4. Each pizza option considered at every step.
// 5. Efficient O(x) solution.
// 6. Works even if slices overshoot target (since overshoot is allowed).