// Coils in Matrix

/*
 * 1. Problem:
 *    - Given n, form two coils in a 4n x 4n matrix.
 *    - Each coil is a sequence of numbers traversed in a spiral-like fashion.
 *
 * 2. Build matrix:
 *    - Fill matrix with numbers from 1 to (4n)^2.
 *
 * 3. Initialize boundaries:
 *    - top, left, down, right to track current layer.
 *
 * 4. Traverse layer:
 *    - First coil: go down left column, then right along bottom row.
 *    - Second coil: go up right column, then left along top row.
 *
 * 5. Alternate coils:
 *    - Use flag to switch between coil1 and coil2.
 *
 * 6. Shrink boundaries:
 *    - Increment top/left, decrement down/right after each layer.
 *
 * 7. Final answer:
 *    - Return vector of two coils containing the sequences.
 */

class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        n *= 4;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<int>> ans(2);
        int a = 1;

        // Step 1: Fill matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = a++;
            }
        }

        // Step 2: Initialize boundaries
        int top = 0, left = 0, down = n - 1, right = n - 1;
        int flag = 1;

        // Step 3: Traverse coils
        while (top < down && left < right) {
            for (int k = top; k < down; k++)
                ans[!flag].push_back(mat[k][left]);
            for (int k = left; k < right; k++)
                ans[!flag].push_back(mat[down][k]);
            for (int k = down; k > top; k--)
                ans[flag].push_back(mat[k][right]);
            for (int k = right; k > left; k--)
                ans[flag].push_back(mat[top][k]);

            // Step 4: Shrink boundaries
            top++; left++; down--; right--;
            flag = !flag;
        }

        return ans;
    }
};

// 🔑 Key Points
// - Matrix size = 4n x 4n.
// - Fill matrix sequentially with numbers.
// - Two coils formed by alternating spiral traversals.
// - Boundaries shrink after each layer.
// - Flag toggles between coil1 and coil2.
// - Answer = vector of two coils.
// - Time complexity: O((4n)^2), Space complexity: O((4n)^2).