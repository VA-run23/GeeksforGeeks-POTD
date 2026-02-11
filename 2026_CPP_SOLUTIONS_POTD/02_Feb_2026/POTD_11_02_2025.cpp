/*
    1. The problem is to minimize the cost of making all heights equal, where changing a height by 1 unit costs proportional to its weight in 'cost'.
    2. The 'helper' function computes the total cost if all heights are adjusted to a target height 'h'.
    3. The 'minCost' function applies a binary search approach over the possible height range [min, max].
    4. At each step, it calculates cost at 'mid' and 'mid+1' to decide which direction reduces cost.
    5. The search narrows until the minimum cost is found, storing the best answer in 'ans'.
    6. Time complexity: O(n log(maxHeight - minHeight)), since each helper call is O(n) and binary search runs log(range).
    7. Space complexity: O(1), as only a few variables are used beyond input arrays.
*/

class Solution {
  public:
    int helper(int h, vector<int>& heights, vector<int>& cost) {
        int val = 0;
        for (int i = 0; i < heights.size(); i++) {
            val += abs(heights[i] - h) * cost[i];
        }
        return val;
    }

     int minCost(vector<int>& heights, vector<int>& cost) {
        //code here
        int left = *min_element(heights.begin(), heights.end());
        int right = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int costMid = helper(mid, heights, cost);
            int costMidPlus = helper(mid + 1, heights, cost);

            ans = min(ans, min(costMid, costMidPlus));

            if (costMid < costMidPlus) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Key points:
// - The cost function is convex, so binary search can be applied over the height range.
// - 'helper' evaluates the cost for a specific target height.
// - Binary search compares mid and mid+1 to decide the direction of search.
// - The algorithm ensures convergence to the minimum cost efficiently.
// - Complexity is dominated by repeated O(n) cost evaluations during log(range) iterations.
