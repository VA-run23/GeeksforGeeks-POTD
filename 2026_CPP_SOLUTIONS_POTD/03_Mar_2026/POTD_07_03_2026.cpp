/*
    1. This code solves the "Dice Throw" problem using recursion with memoization.
    2. The helper function recursively calculates ways to reach a target sum with given dice and faces.
    3. Base cases: if sum is 0, return true only if no dice remain; if sum < 0 or no dice left, return 0.
    4. Memoization is applied using a 2D dp table to avoid recomputation of overlapping subproblems.
    5. For each dice roll, it tries all face values (1 to faces) and accumulates valid ways.
    6. Time Complexity: O(n * x * m), where n = number of dice, x = target sum, m = faces per dice.
    7. Space Complexity: O(n * x) due to the dp table storing intermediate results.
*/

class Solution {
public:
    int helper(int faces, int dices, int sum, vector<vector<int>>& dp) {
        if (!sum)
            return !dices;
        if (sum < 0 || !dices)
            return 0;
        if (dp[dices][sum] != -1)
            return dp[dices][sum];
        int cnt = 0;
        for (int i = 1; i <= faces; i++) {
            cnt += helper(faces, dices - 1, sum - i, dp);
        }
        return dp[dices][sum] = cnt;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return helper(m, n, x, dp);
    }
};

// Key points:
// - Problem: Count ways to achieve a target sum using n dice with m faces.
// - Approach: Recursion + memoization to avoid redundant calculations.
// - Base cases handle invalid sums and dice exhaustion.
// - DP table ensures overlapping subproblems are cached.
// - Time complexity grows with dice, sum, and faces, but memoization keeps it efficient.
// - Space complexity is proportional to dice × sum.
// - This is a classic dynamic programming problem with combinatorial counting.
