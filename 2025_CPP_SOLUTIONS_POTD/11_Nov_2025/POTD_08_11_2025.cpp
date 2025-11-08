/*
    1. This code counts the number of paths from top-left to bottom-right in a matrix where the sum of coins collected equals exactly k.
    2. The 'helper' function recursively explores two directions—right and down—while accumulating coin values and pruning paths that exceed k.
    3. Memoization is used via a 3D vector 'dp[cr][cc][coins]' to store intermediate results and avoid recomputation.
    4. The base case returns 1 if the destination is reached and the coin sum equals k; otherwise, it returns 0.
    5. The recursive calls accumulate valid paths and store the result in 'dp' to reuse in overlapping subproblems.
    6. The 'numberOfPath' function initializes the memoization table and starts the recursive traversal from cell (0,0) with 0 coins.
    7. Time Complexity: O(n * m * k); Space Complexity: O(n * m * k) due to the 3D DP table.
*/

class Solution {
public:
    int helper(vector<vector<int>>& mat, int k, int m, int n,
               int cr, int cc, int coins,
               vector<vector<vector<int>>>& dp) {
        if (cr >= m || cc >= n || coins > k) return 0;

        coins += mat[cr][cc];
        if (coins > k) return 0;

        if (cr == m - 1 && cc == n - 1)
            return coins == k ? 1 : 0;

        if (dp[cr][cc][coins] != -1) return dp[cr][cc][coins];

        int right = helper(mat, k, m, n, cr, cc + 1, coins, dp);
        int down = helper(mat, k, m, n, cr + 1, cc, coins, dp);

        return dp[cr][cc][coins] = right + down;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return helper(mat, k, m, n, 0, 0, 0, dp);
    }
};