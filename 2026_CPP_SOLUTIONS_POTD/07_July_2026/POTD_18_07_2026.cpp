// Cut Matrix Problem

/*
 *    1. The matrix is divided into k parts such that each part has a positive sum.
 *    2. Build a suffix sum matrix to quickly compute submatrix sums starting at any (r, c).
 *    3. Initialize DP where dp[rem][r][c] represents ways to cut matrix into rem parts starting at (r, c).
 *    4. Base case: if suffix sum at (r, c) > 0, then dp[1][r][c] = 1.
 *    5. For each rem > 1, compute possible cuts using cumulative row and column sums.
 *    6. Use binary search helpers (findNextRow, findNextCol) to locate valid cut positions.
 *    7. Time Complexity: O(k * n * m * log(max(n,m))), Space Complexity: O(k * n * m).
 */

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int findWays(vector<vector<int>>& matrix, int k) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suff[i][j] = matrix[i][j]
                           + suff[i + 1][j]
                           + suff[i][j + 1]
                           - suff[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(
            k + 1,
            vector<vector<int>>(n, vector<int>(m, 0))
        );

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (suff[r][c] > 0)
                    dp[1][r][c] = 1;
            }
        }

        for (int rem = 2; rem <= k; rem++) {
            vector<vector<int>> rowSum(n + 1, vector<int>(m, 0));
            vector<vector<int>> colSum(n, vector<int>(m + 1, 0));

            for (int r = n - 1; r >= 0; r--) {
                for (int c = m - 1; c >= 0; c--) {
                    rowSum[r][c] =
                        (dp[rem - 1][r][c] + rowSum[r + 1][c]) % MOD;

                    colSum[r][c] =
                        (dp[rem - 1][r][c] + colSum[r][c + 1]) % MOD;
                }
            }

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (suff[r][c] == 0) continue;

                    long long totalWays = 0;

                    int next_r = findNextRow(suff, r, c, n);
                    if (next_r < n) {
                        totalWays = (totalWays + rowSum[next_r][c]) % MOD;
                    }

                    int next_c = findNextCol(suff, r, c, m);
                    if (next_c < m) {
                        totalWays = (totalWays + colSum[r][next_c]) % MOD;
                    }

                    dp[rem][r][c] = totalWays;
                }
            }
        }

        return dp[k][0][0];
    }

private:
    int findNextRow(vector<vector<int>>& suff, int r, int c, int n) {
        int low = r + 1, high = n, ans = n;
        int target = suff[r][c];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suff[mid][c] < target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int findNextCol(vector<vector<int>>& suff, int r, int c, int m) {
        int low = c + 1, high = m, ans = m;
        int target = suff[r][c];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suff[r][mid] < target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
 
// Key Points
// 1. Suffix sum matrix enables fast submatrix sum queries.
// 2. DP state tracks ways to cut matrix into k parts.
// 3. Base case ensures only positive submatrices are valid.
// 4. Row and column cumulative sums speed up DP transitions.
// 5. Binary search finds next valid cut positions efficiently.
// 6. Modulo arithmetic prevents overflow in large counts.
// 7. Optimized solution combining DP, suffix sums, and binary search.