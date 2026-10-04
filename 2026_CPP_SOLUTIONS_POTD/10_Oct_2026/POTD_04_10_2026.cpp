// Perimeter of Shapes in Binary Matrix

/*
 * 1. Problem:
 *    - Given a binary matrix where 1 represents filled cells and 0 represents empty cells.
 *    - Find the total perimeter of all shapes formed by 1s.
 *
 * 2. Initialize perimeter counter.
 *    - peri = 0.
 *
 * 3. Traverse each cell in the matrix.
 *    - If cell = 1, it contributes 4 to perimeter initially.
 *
 * 4. Check upper neighbor.
 *    - If mat[i-1][j] = 1, subtract 2 (shared edge).
 *
 * 5. Check left neighbor.
 *    - If mat[i][j-1] = 1, subtract 2 (shared edge).
 *
 * 6. Continue for all cells.
 *    - Each shared edge reduces perimeter by 2.
 *
 * 7. Final answer:
 *    - Return total perimeter after adjustments.
 */

class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int peri = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    peri += 4;
                    if (i > 0 && mat[i - 1][j]) peri -= 2;
                    if (j > 0 && mat[i][j - 1]) peri -= 2;
                }
            }
        }
        return peri;
    }
};

// 🔑 Key Points
// - Each filled cell contributes 4 to perimeter.
// - Shared edges subtract 2 from perimeter.
// - Only check top and left neighbors to avoid double counting.
// - Efficient O(n*m) solution.
// - Space complexity: O(1).
// - Works for multiple disconnected shapes.
// - Handles rectangular matrices of any size.