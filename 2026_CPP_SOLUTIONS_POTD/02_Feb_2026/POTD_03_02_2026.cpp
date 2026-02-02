/*
    1. This function solves the "Best Time to Buy and Sell Stock" problem.
    2. It tracks the minimum price seen so far while iterating through the prices array.
    3. For each price, it calculates the potential profit if sold at that price after buying at the minimum price.
    4. The maximum profit is updated whenever a higher profit is found.
    5. Variable `minPrice` ensures we always consider the lowest buying price up to the current day.
    6. Time Complexity: O(n), since we traverse the array once.
    7. Space Complexity: O(1), as only a few variables are used regardless of input size.
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int ans = 0;
        int minPrice= prices[0];
        for(auto i: prices){
            minPrice = min(minPrice, i);
            ans = max(ans, i - minPrice);
        }
        return ans;
    }
};

// Key points:
// - The algorithm uses a single pass to track min price and max profit.
// - It avoids nested loops, making it efficient compared to brute force.
// - The logic ensures profit is only calculated when selling after buying.
// - Optimal because it achieves O(n) time and O(1) space.
// - Simple yet powerful: just track min so far and max difference.
