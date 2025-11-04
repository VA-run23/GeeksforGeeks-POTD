/*
    1. This function calculates the minimum cost for a frog to reach the last stair, given jump costs based on height differences.
    2. It uses dynamic programming to build up the solution, storing the minimum cost to reach each stair in a dp[] array.
    3. The frog can jump either one or two stairs at a time, and the cost is the absolute difference in heights.
    4. dp[0] is initialized to 0 since the frog starts there; dp[1] is the cost to jump from stair 0 to 1.
    5. For each stair i ≥ 2, we compute the minimum cost to reach it from either i-1 or i-2.
    6. The recurrence relation is: dp[i] = min(dp[i-1] + |hi - hi-1|, dp[i-2] + |hi - hi-2|).
    7. Time Complexity: O(n), Space Complexity: O(n) due to the dp array storing costs for each stair.
*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        if (n > 1)
            dp[1] = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = min(
                dp[i - 1] + abs(height[i] - height[i - 1]),
                dp[i - 2] + abs(height[i] - height[i - 2])
            );
        }

        return dp[n - 1];
    }
};