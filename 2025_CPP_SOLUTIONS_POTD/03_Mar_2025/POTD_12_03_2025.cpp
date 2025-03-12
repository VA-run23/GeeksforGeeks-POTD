/*
1. The function calculates the minimum cost to climb a staircase given a cost for each step.
2. `n` holds the number of steps, and a `dp` vector is initialized to store the minimum cost to reach each step.
3. The `dp` array includes an extra space to account for climbing past the last step (`n`).
4. Starting from step 2, the loop calculates the minimum cost to reach step `i`.
5. At each step, the cost is determined by adding the current step cost to the smaller of the costs of the previous two steps.
6. The final value in `dp[n]` represents the minimum cost to climb to or beyond the top of the stairs.
7. The result, `dp[n]`, is returned as the minimum total cost.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n + 1, 0); // dp array to store minimum costs

        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};