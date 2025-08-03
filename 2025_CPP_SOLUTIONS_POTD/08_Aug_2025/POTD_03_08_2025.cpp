/*
    1. Initialize a (n+1)×(m+1) difference matrix 'diff' with zeros to mark submatrix boundaries safely.
    2. For each operation [v, r1, c1, r2, c2], update the corners of 'diff' to encode the range addition.
    3. Apply row-wise prefix sums to spread horizontal influence of each operation across rows.
    4. Apply column-wise prefix sums to spread vertical influence of each operation across columns.
    5. Add the resulting 'diff' matrix to the original 'mat' to get the final updated matrix.
    6. This avoids brute-force updates and ensures each operation is applied in constant time.
    7. Time Complexity: O(n × m + q), Space Complexity: O(n × m) — efficient for large inputs.
*/

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));

        for (auto& q : opr) {
            int v = q[0];
            int r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];

            diff[r1][c1] += v;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                diff[i][j] += diff[i][j - 1];

        for (int j = 0; j < m; ++j)
            for (int i = 1; i < n; ++i)
                diff[i][j] += diff[i - 1][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mat[i][j] += diff[i][j];

        return mat;
    }
};