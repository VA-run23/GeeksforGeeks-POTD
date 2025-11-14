/*
    1. The function first checks feasibility: merging into one pile is only possible if (n-1) % (k-1) == 0.
    2. It builds a prefix sum array to quickly compute the sum of stones in any interval [l, r].
    3. Two DP tables are used: dp[i][j] = min cost to merge stones[i..j] into 1 pile, dp2[i][j] = min cost to merge into any valid number of piles.
    4. For each interval length, the code tries splitting the segment into subintervals at steps of (k-1), ensuring pile compatibility.
    5. dp2[i][j] stores the minimum cost of merging subintervals without necessarily forming one pile.
    6. If the interval length allows merging into a single pile ((j-i) % (k-1) == 0), dp[i][j] = dp2[i][j] + sum(i,j).
    7. Finally, dp[0][n-1] gives the minimum cost to merge the entire array into one pile, or -1 if impossible.

    Time Complexity: O(n^3 / k) → roughly cubic due to interval splits and DP transitions.
    Space Complexity: O(n^2) → two DP tables of size n×n plus prefix sums.
*/

class Solution {
  public:
    int mergeStones(vector<int> &stones, int k) {
        // code here
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        auto sum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> dp2(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp2[i][j] = INF;
                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp2[i][j] = min(dp2[i][j], dp[i][mid] + dp[mid + 1][j]);
                }

                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] = dp2[i][j] + sum(i, j);
                } else {
                    dp[i][j] = dp2[i][j];
                }
            }
        }
        return dp[0][n - 1];
    }
};