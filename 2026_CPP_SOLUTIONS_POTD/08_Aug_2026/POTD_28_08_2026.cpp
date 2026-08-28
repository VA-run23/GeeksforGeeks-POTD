// Minimum Cost Selection (Buying Vegetables)

/*
 *    1. The problem asks to minimize the cost of buying vegetables across n days with 3 choices each day.
 *    2. Constraint: cannot buy the same vegetable on consecutive days.
 *    3. Use dynamic programming to track minimum cost for each choice at every day.
 *    4. Transition: cost[i][j] = mat[i][j] + min(cost[i-1][k]) for k ≠ j.
 *    5. Initialize first day costs directly from mat[0].
 *    6. Iteratively update costs for each day using previous day’s values.
 *    7. Final answer = min of last day’s three costs.
 */

class Solution {
  public:
    int minCost(vector<vector<int>> &mat) {
        // code here
        int a = mat[0][0], b = mat[0][1], c = mat[0][2];
        for (int i = 1; i < mat.size(); i++) {
            int na = mat[i][0] + min(b, c);
            int nb = mat[i][1] + min(a, c);
            int nc = mat[i][2] + min(a, b);
            a = na; b = nb; c = nc;
        }
        return min({a, b, c});
    }
};

// Key Points
// 1. DP tracks minimum cost for each vegetable choice.
// 2. Cannot pick same vegetable on consecutive days.
// 3. Transition uses min of other two previous costs.
// 4. Base case initialized from first day’s costs.
// 5. Iteratively updates costs for all days.
// 6. Final answer is min of last day’s three options.
// 7. Runs in O(n) time with O(1) space.