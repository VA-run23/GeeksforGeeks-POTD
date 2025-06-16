/*
    1. We pair each tower’s height with its cost and sort the towers by height to enable efficient prefix calculations.
    2. The prefix arrays 'pc' and 'prefixSum' store cumulative costs and height-cost products, which will help compute adjustment costs.
    3. For each tower, we consider making all towers equal to its height and compute cost to adjust smaller and taller towers separately.
    4. 'left' computes the cost to raise all shorter towers, using prefix sums to avoid nested loops.
    5. 'right' computes the cost to reduce all taller towers in similar fashion using suffix logic with prefix arrays.
    6. The minimum total adjustment cost among all possible target heights is tracked and returned.
    7. Time complexity: O(n log n) due to sorting; Space complexity: O(n) for prefix arrays.
*/

class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        vector<pair<int, int>> towers(n);
        for (int i = 0; i < n; ++i) {
            towers[i] = {heights[i], cost[i]};
        }
        sort(towers.begin(), towers.end());

        vector<long long> pc(n), prefixSum(n);
        pc[0] = towers[0].second;
        prefixSum[0] = 1LL * towers[0].first * towers[0].second;
        for (int i = 1; i < n; ++i) {
            pc[i] = pc[i - 1] + towers[i].second;
            prefixSum[i] = prefixSum[i - 1] + 1LL * towers[i].first * towers[i].second;
        }

        long long result = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long left = (i > 0) ? 1LL * towers[i].first * pc[i - 1] - prefixSum[i - 1] : 0;
            long long right = (i < n - 1) ?
                (prefixSum[n - 1] - prefixSum[i]) - 1LL * towers[i].first * (pc[n - 1] - pc[i]) : 0;
            result = min(result, left + right);
        }
        return result;
    }
};
