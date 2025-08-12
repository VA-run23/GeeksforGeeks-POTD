/*
    1. If k == 0, no free candies are offered, so total cost is the sum of all prices for both min and max.
    2. For minimum cost, sort prices in ascending order and buy the cheapest candy while skipping k most expensive ones each time.
    3. For maximum cost, sort prices in descending order and buy the most expensive candy while skipping k cheapest ones each time.
    4. Two-pointer technique is used: one pointer buys a candy, the other skips k candies.
    5. This ensures the maximum number of free candies is taken per purchase, as per the problem's condition.
    6. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) if sorting in-place, otherwise O(n).
    7. Returns a vector with [minCost, maxCost] representing the least and most money needed to buy all candies.
*/

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        if (k == 0) {
            int total = accumulate(prices.begin(), prices.end(), 0);
            return {total, total};
        }

        sort(prices.begin(), prices.end()); 
        int minCost = 0;
        int i = 0, j = prices.size() - 1;

        while (i <= j) {
            minCost += prices[i++];
            j -= k; 
        }

        sort(prices.begin(), prices.end(), greater<int>()); 
        int maxCost = 0;
        i = 0, j = prices.size() - 1;

        while (i <= j) {
            maxCost += prices[i++];
            j -= k; 
        }

        return {minCost, maxCost};
    }
};