/*
    1. The function counts how many square submatrices in 'mat' have a sum equal to 'x'.
    2. It first builds a 2D prefix sum array 'prefix' to quickly compute sums of submatrices.
    3. Each 'prefix[i][j]' stores the sum of elements from (0,0) to (i-1,j-1).
    4. Then, for every possible square size 'k', it iterates over all valid top-left corners.
    5. Using the prefix sums, it calculates the sum of each square in O(1) time.
    6. If the sum equals 'x', it increments the counter.
    7. Time Complexity: O(n^2 * m^2) in worst case; Space Complexity: O(n*m).
*/

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        int count = 0;
        for (int k = 1; k <= min(n, m); k++) {
            for (int i = 1; (i + k - 1) <= n; i++) {
                for (int j = 1; (j + k - 1) <= m; j++) {
                    int s = prefix[i + k - 1][j + k - 1] -
                            prefix[i + k - 1][j - 1] -
                            prefix[i - 1][j + k - 1] + prefix[i - 1][j - 1];

                    if (s == x)
                        count++;
                }
            }
        }

        return count;
    }
};

// Key points:
// - Prefix sums allow O(1) submatrix sum queries.
// - The algorithm checks all square sizes from 1 to min(n,m).
// - For each square, it computes sum using inclusion-exclusion on prefix array.
// - Brute force without prefix would be slower (O(n^3*m^3)).
// - Current approach reduces sum calculation cost but still iterates over all squares.
// - Time complexity is O(n^2*m^2), space O(n*m).
// - Useful for problems where exact submatrix sum matches are required.
