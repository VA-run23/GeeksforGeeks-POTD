/*
1. This class solves the classic 0/1 Knapsack problem using recursion and memoization
   to optimize the computation for maximum value within a given weight limit (W).

2. The `helper` function is a recursive method that calculates the maximum value
   by including or excluding the current item, using memoization to store results.

3. The base case in `helper` ensures recursion stops when either all items are
   considered (`i == n`) or the weight limit `W` becomes 0.

4. Memoization is implemented with a 2D vector `maxVal`, where each `maxVal[i][W]`
   stores the maximum value for a given combination of items (from index i onwards)
   and weight capacity W.

5. If the current item's weight `wt[i]` is less than or equal to `W`, two options
   are considered: including the item or excluding it. The maximum of these options
   is stored in `maxVal[i][W]`.

6. If the current item's weight is greater than `W`, the item is excluded, and the
   recursion continues with the next item.

7. The `knapsack` method initializes the `maxVal` vector and invokes the `helper`
   function, starting from the first item and the full weight capacity, returning
   the computed maximum value.
*/

class Solution {
  public:
    int helper(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& maxVal) {
        int n = val.size();
        if (i == n || W == 0) {
            return 0;
        }
        if (maxVal[i][W] != -1) {
            return maxVal[i][W];
        }
        if (wt[i] <= W) {
            maxVal[i][W] = max(val[i] + helper(i + 1, W - wt[i], val, wt, maxVal),
                               helper(i + 1, W, val, wt, maxVal));
        } else {
            maxVal[i][W] = helper(i + 1, W, val, wt, maxVal);
        }
        return maxVal[i][W];
    }
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        // code here
        int n = val.size();
        vector<vector<int>> maxVal(n, vector<int>(W + 1, -1));
        return helper(0, W, val, wt, maxVal);
    }
};