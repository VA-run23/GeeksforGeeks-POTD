// Largest Zigzag Sequence

/*
 *    1. The problem asks to find the maximum zigzag sequence sum in a square matrix.
 *    2. A zigzag sequence is formed by picking one element from each row, ensuring no two consecutive elements are from the same column.
 *    3. Initialize the first row of dp with the matrix values directly.
 *    4. For each subsequent row i and column j, compute the best possible sum by checking all dp[i-1][k] where k ≠ j.
 *    5. Transition: dp[i][j] = mat[i][j] + max(dp[i-1][k]) for all k ≠ j.
 *    6. The answer is the maximum value in the last row of the dp table.
 *    7. Time Complexity: O(n³) due to nested loops, Space Complexity: O(n²).
 */

class Solution {
  public:
    int zigzagSequence(vector<vector<int>> & mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int best = 0;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    best = max(best, dp[i - 1][k]);
                }
                dp[i][j] = mat[i][j] + best;
            }
        }
        
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Key Points
// 1. Defines zigzag as picking one element per row, avoiding same column consecutively.
// 2. Initializes dp with first row values.
// 3. Transition checks all previous row columns except current.
// 4. dp[i][j] = mat[i][j] + max(dp[i-1][k]) for k ≠ j.
// 5. Answer is maximum in last row of dp table.
// 6. Runs in O(n³) time, O(n²) space.
// 7. Straightforward DP solution but can be optimized further.
