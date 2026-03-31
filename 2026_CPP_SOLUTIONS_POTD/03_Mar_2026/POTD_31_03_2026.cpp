// Buy Stock with Transaction Fee

/*
 *    1. This problem involves maximizing profit from stock trading with a transaction fee.
 *    2. At each index, you decide whether to buy, sell, or skip based on current state.
 *    3. A recursive approach with memoization is used to avoid recalculating subproblems.
 *    4. The `buy` state indicates whether you can buy (1) or must sell (0).
 *    5. Transaction fee is subtracted when selling to account for costs.
 *    6. Dynamic programming table `dp` stores results for each index and state.
 *    7. Time Complexity: O(n), Space Complexity: O(n) due to memoization.
 */

class Solution {
public:
    vector<vector<int>> dp;
    int recur(vector<int>& arr, int idx, int buy, int fee) {
        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        if (buy) {
            int take = recur(arr, idx + 1, 0, fee) - arr[idx];
            int didnot = recur(arr, idx + 1, buy, fee);
            return dp[idx][buy] = max(take, didnot);
        } else {
            int sell = recur(arr, idx + 1, 1, fee) + arr[idx] - fee;
            int didnot = recur(arr, idx + 1, buy, fee);
            return dp[idx][buy] = max(sell, didnot);
        }
    }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        dp = vector<vector<int>>(arr.size() + 1, vector<int>(2, -1));
        return recur(arr, 0, 1, k);
    }
};

// Key Points
// 1. Recursive + memoization approach avoids redundant calculations.
// 2. `buy` state tracks whether you can buy or must sell.
// 3. Transaction fee is applied only during selling.
// 4. DP table ensures O(n) time complexity.
// 5. Base case: when index exceeds array size, profit is 0.
// 6. Each decision compares taking action vs skipping.
// 7. Space complexity can be optimized to O(1) using variables instead of DP.