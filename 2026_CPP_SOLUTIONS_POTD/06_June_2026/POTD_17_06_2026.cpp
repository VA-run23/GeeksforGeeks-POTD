// Maximize Product by Cutting Rope

/*
 *    1. We are given a rope of length n.
 *    2. The task is to cut the rope into integer lengths.
 *    3. Each cut should maximize the product of the resulting lengths.
 *    4. Dynamic Programming is used to store subproblem results.
 *    5. For each length i, we try all possible cuts j.
 *    6. We compare direct product (j*(i-j)) and recursive product (dp[i-j]*j).
 *    7. Time Complexity: O(n^2), Space Complexity: O(n).
 */

class Solution {
    public:
    int maxProduct(int n) {
        // code here
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int t = 0;
            for (int j = 1; j<i; j++) {
                t = max({t, (i - j)*j, dp[i - j]*j});
            }
            dp[i] = max(dp[i], t);
        }
        return dp[n];
    }
};

// Key Points
// 1. Problem is a variation of integer break.
// 2. Dynamic Programming ensures optimal substructure usage.
// 3. dp[i] stores maximum product for rope length i.
// 4. Each cut is evaluated for direct and recursive product.
// 5. Base case: dp[1] = 1.
// 6. Iterative approach avoids recomputation.
// 7. Complexity is quadratic, but efficient for moderate n.