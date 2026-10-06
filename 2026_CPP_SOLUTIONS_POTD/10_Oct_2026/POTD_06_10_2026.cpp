// Longest Increasing Path in Matrix

/*
 * 1. Problem:
 *    - Given a matrix, find the length of the longest strictly increasing path.
 *    - You can move in 4 directions (up, down, left, right).
 *
 * 2. Approach:
 *    - Use DFS + memoization (top-down DP).
 *
 * 3. Define recursive function rec(row, col):
 *    - Returns longest increasing path starting at (row, col).
 *
 * 4. Base case:
 *    - If dp[row][col] already computed, return it.
 *
 * 5. Transition:
 *    - Initialize sum = 1 (current cell).
 *    - For each neighbor (rV, cV):
 *        If matrix[rV][cV] > matrix[row][col],
 *        sum = max(sum, 1 + rec(rV, cV)).
 *
 * 6. Memoize result:
 *    - dp[row][col] = sum.
 *
 * 7. Final answer:
 *    - Iterate over all cells, compute rec(i, j).
 *    - Return maximum path length found.
 */

class Solution {
  public:
    int rec(int row, int n, int col, int m, vector<vector<int>> &matrix,
            vector<vector<int>> &dp, int rN[], int cN[]) {
        if (dp[row][col] != -1) return dp[row][col];
        int sum = 1;
        for (int i = 0; i < 4; i++) {
            int rV = row + rN[i];
            int cV = col + cN[i];
            if (rV >= 0 && rV < n && cV >= 0 && cV < m &&
                matrix[row][col] < matrix[rV][cV]) {
                sum = max(sum, 1 + rec(rV, n, cV, m, matrix, dp, rN, cN));
            }
        }
        return dp[row][col] = sum;
    }

    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int rN[] = {-1, 0, 1, 0};
        int cN[] = {0, 1, 0, -1};
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, rec(i, n, j, m, matrix, dp, rN, cN));
            }
        }
        return ans;
    }
};

// 🔑 Key Points
// - DFS + memoization avoids recomputation.
// - Each cell stores longest path starting there.
// - Only move to strictly larger neighbors.
// - Answer = maximum path length across all cells.
// - Time complexity: O(n*m).
// - Space complexity: O(n*m) for dp.
// - Efficient solution for large matrices.