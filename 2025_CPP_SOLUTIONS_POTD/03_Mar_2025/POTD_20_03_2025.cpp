/*
1. Check if the prices array is empty; if yes, return 0 since no transactions can be made.
2. Use a `leftProfit` array to calculate the maximum profit for one transaction ending on or before each day.
3. Track the minimum price encountered so far, updating `leftProfit` as the difference between the current price and `minPrice`.
4. Use a `rightProfit` array to calculate the maximum profit for one transaction starting on or after each day.
5. Track the maximum price encountered from the end of the array, updating `rightProfit` as the difference between `maxPrice` and the current price.
6. Combine results from `leftProfit` and `rightProfit` for each day to determine the total maximum profit achievable.
7. Return the maximum value found, representing the highest combined profit from at most two transactions.
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> leftProfit(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }

        vector<int> rightProfit(n, 0);
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
    }
};