// Count Spanning Trees in a Graph

/*
 *    1. Build the Laplacian matrix of the graph using degrees and adjacency.
 *    2. The Laplacian is an n×n matrix where diagonal entries are vertex degrees.
 *    3. Off-diagonal entries are -1 if an edge exists between two vertices.
 *    4. To count spanning trees, compute any cofactor of the Laplacian.
 *    5. Cofactor is obtained by deleting one row and one column.
 *    6. Determinant of this cofactor gives the number of spanning trees.
 *    7. Time Complexity: O(n^3) due to determinant calculation; Space Complexity: O(n^2).
 */

class Solution {
  public:
    long long determinant(vector<vector<double>> mat, int n) {

        double det = 1;

        for (int i = 0; i < n; i++) {

            int pivot = i;

            for (int j = i + 1; j < n; j++) {
                if (abs(mat[j][i]) > abs(mat[pivot][i]))
                    pivot = j;
            }

            if (abs(mat[pivot][i]) < 1e-9)
                return 0;

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++) {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {

        vector<vector<double>> lap(n, vector<double>(n, 0));

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        vector<vector<double>> cofactor(n - 1,
                                        vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cofactor[i][j] = lap[i][j];
            }
        }

        return determinant(cofactor, n - 1);
    }
};

// Key Points
// 1. Uses Kirchhoff’s Matrix Tree Theorem.
// 2. Constructs Laplacian matrix from graph edges.
// 3. Cofactor of Laplacian gives spanning tree count.
// 4. Determinant is computed via Gaussian elimination.
// 5. Pivoting ensures numerical stability.
// 6. Rounding handles floating-point precision issues.
// 7. Complexity is cubic in n, suitable for small graphs.