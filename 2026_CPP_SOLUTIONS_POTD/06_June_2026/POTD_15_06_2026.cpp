// Minimum cost to fill given weight in a bag

/*
 *    1. We are given costs of items with specific weights.
 *    2. Each index i in cost[] represents the cost of weight (i+1).
 *    3. Some weights may be unavailable, marked as -1 in cost[].
 *    4. We need to find the minimum cost to fill exactly weight w.
 *    5. A recursive + memoization approach is used to avoid recomputation.
 *    6. dp[w] stores the minimum cost to achieve weight w.
 *    7. Time Complexity: O(w * n), Space Complexity: O(w) due to DP array.
 */

class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& cost, int w) {
        if (dp[w] != -1)
            return dp[w];

        int res = INT_MAX;
        for (int i = 0; i < w && i < cost.size(); i++)
            if (cost[i] != -1) {
                int val = solve(cost, w - i - 1);
                if (val != INT_MAX)
                    val += cost[i];
                res = min(res, val);
            }
        return dp[w] = res;
    }
    int minimumCost(vector<int> &cost, int w) {
        // code here
        dp = vector<int>(w + 1, -1);
        dp[0] = 0;
        int val = solve(cost, w);
        return val == INT_MAX ? -1 : val;
    }
};

// Key Points
// 1. Uses recursion with memoization to avoid repeated calculations.
// 2. dp[w] stores the minimum cost for weight w.
// 3. Handles unavailable weights with cost[i] == -1.
// 4. Base case: dp[0] = 0 (zero cost for zero weight).
// 5. Returns -1 if weight cannot be filled exactly.
// 6. Iterates through all possible smaller weights to build solution.
// 7. Complexity is polynomial, but can be optimized with bottom-up DP.