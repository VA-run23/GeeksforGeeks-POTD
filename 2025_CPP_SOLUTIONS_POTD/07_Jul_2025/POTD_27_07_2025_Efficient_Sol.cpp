/*
    1. The function sets entire rows and columns to 0 if any element in them is 0, modifying the matrix in-place.
    2. It first checks if the first row or first column needs to be zeroed, and stores the result in flags 'row0' and 'col0'.
    3. The matrix is then scanned (excluding first row and column), and markers are set in the first row and column wherever a 0 is found.
    4. These markers help determine which rows and columns need to be zeroed without using extra space.
    5. The cells (excluding first row and column) are updated based on these markers to zero out necessary parts.
    6. Finally, based on the initial flags, the first row and column are zeroed if required.
    7. Time Complexity: O(n × m), Space Complexity: O(1) — no extra storage is used beyond a few variables.
*/

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool row0 = false, col0 = false;

        for (int i = 0; i < n; i++)
            if (mat[i][0] == 0) col0 = true;

        for (int j = 0; j < m; j++)
            if (mat[0][j] == 0) row0 = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }

        if (col0)
            for (int i = 0; i < n; i++) mat[i][0] = 0;

        if (row0)
            for (int j = 0; j < m; j++) mat[0][j] = 0;
    }
};
