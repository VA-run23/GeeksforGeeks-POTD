
/* 
1. This code implements a solution to find the maximum profit achievable by making up to 'k' stock transactions, using dynamic programming.
2. If 'k' exceeds half the number of days, it simplifies to unlimited transactions (greedy approach by summing all positive differences in stock prices).
3. Otherwise, a 2D DP table is created where 'dp[i][j]' represents the max profit achievable with 'i' transactions up to day 'j'.
4. For each transaction 'i', the variable 'maxDiff' is used to track the maximum difference between the profits of previous transactions and the current stock price.
5. The inner loop calculates the profit either by skipping a transaction or by selling the stock at the current price, whichever is better.
6. The 'maxDiff' variable updates dynamically to optimize the current profit calculation for future days.
7. Finally, the result is stored in 'dp[k][n-1]', representing the max profit with 'k' transactions over all days.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        if (k > n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += (prices[i] - prices[i - 1]);
                }
            }
            return profit;
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }
};

