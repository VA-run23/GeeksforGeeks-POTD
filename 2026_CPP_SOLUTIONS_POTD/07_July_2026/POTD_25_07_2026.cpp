// Max Sum Square Sub-Matrix of Size k

/*
 *    1. The problem asks for the maximum sum of any k x k sub-matrix in a given N x N matrix.
 *    2. Use prefix sum (2D cumulative sum) to quickly compute sub-matrix sums.
 *    3. Build a dp table where dp[i][j] stores sum of elements in rectangle (0,0) to (i-1,j-1).
 *    4. Formula:
 *       dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
 *    5. For each (i,j) representing bottom-right corner of a k x k sub-matrix:
 *       sum = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k]
 *    6. Track maximum sum across all valid sub-matrices.
 *    7. Time Complexity: O(N^2), Space Complexity: O(N^2).
 */

class Solution {
  public:
    int maximumSum(vector<vector<int>> &mat, int k) {
        int N = mat.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        int ans = INT_MIN;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = mat[i - 1][j - 1] 
                         + dp[i - 1][j] 
                         + dp[i][j - 1] 
                         - dp[i - 1][j - 1];

                if (i >= k && j >= k) {
                    int sum = dp[i][j] 
                            - dp[i - k][j] 
                            - dp[i][j - k] 
                            + dp[i - k][j - k];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};

// Key Points
// 1. Prefix sum allows O(1) sub-matrix sum queries.
// 2. dp[i][j] stores cumulative sum up to (i-1,j-1).
// 3. Sub-matrix sum formula uses inclusion-exclusion.
// 4. Iterate over all possible k x k sub-matrix bottom-right corners.
// 5. Efficient O(N^2) solution compared to naive O(N^2 * k^2).