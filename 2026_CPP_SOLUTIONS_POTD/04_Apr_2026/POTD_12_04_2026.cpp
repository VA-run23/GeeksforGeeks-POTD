// Toeplitz Matrix

/*
 *    1. A Toeplitz matrix has constant diagonals from top-left to bottom-right.
 *    2. This means every element at (i, j) must equal the element at (i+1, j+1).
 *    3. We iterate through the matrix excluding the last row and column.
 *    4. Compare each element with its diagonal neighbor.
 *    5. If any mismatch is found, return false immediately.
 *    6. If no mismatches are found, return true.
 *    7. Time Complexity: O(n*m), Space Complexity: O(1).
 */

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (mat[i][j] != mat[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Key Points
// 1. Toeplitz matrix requires equal diagonals.
// 2. Only adjacent diagonal elements need comparison.
// 3. Last row and column are excluded from checks.
// 4. Early exit improves efficiency when mismatch is found.
// 5. Works for rectangular as well as square matrices.
// 6. No extra memory is required.
// 7. Straightforward nested loop solution.