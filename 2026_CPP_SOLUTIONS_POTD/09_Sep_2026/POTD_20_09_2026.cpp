// Largest Subsquare Surrounded by X

/*
 *    1. The problem asks to find the largest square in a matrix such that all four sides are made of 'X'.
 *    2. Approach:
 *       - Precompute row[r][c] = number of consecutive 'X' ending at (r,c) in the row.
 *       - Precompute col[r][c] = number of consecutive 'X' ending at (r,c) in the column.
 *    3. For each cell (r,c), consider it as the bottom-right corner of a square.
 *       - The maximum possible size is min(row[r][c], col[r][c]).
 *       - Check if top side and left side also have enough consecutive 'X'.
 *    4. If valid, update result with this size.
 *    5. Iterate over all cells to find the largest valid square.
 *    6. Time Complexity: O(n*m*min(n,m)), Space Complexity: O(n*m).
 */

class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));

        // Step 1: Precompute row and col counts
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (mat[r][c] == 'X') {
                    row[r][c] = (c == 0 ? 1 : row[r][c - 1] + 1);
                    col[r][c] = (r == 0 ? 1 : col[r - 1][c] + 1);
                } else {
                    row[r][c] = 0;
                    col[r][c] = 0;
                }
            }
        }

        int result = 0;

        // Step 2: Check possible squares
        for (int r = n - 1; r >= 0; r--) {
            for (int c = m - 1; c >= 0; c--) {
                int size = min(row[r][c], col[r][c]);

                while (size > result) {
                    if ((r - size + 1) >= 0 && (c - size + 1) >= 0 &&
                        row[r][c] >= size && col[r][c] >= size &&
                        row[r - size + 1][c] >= size &&
                        col[r][c - size + 1] >= size) {
                        result = size;
                        break;
                    } else {
                        size--;
                    }
                }
            }
        }

        return result;
    }
};

// Key Points
// 1. Precompute consecutive 'X' counts row-wise and column-wise.
// 2. Each cell can be bottom-right corner of a square.
// 3. Maximum possible size = min(row[r][c], col[r][c]).
// 4. Validate top and left boundaries.
// 5. Update result if valid square found.
// 6. Efficient O(n*m*min(n,m)) solution.
// 7. Uses DP-style preprocessing for quick boundary checks.