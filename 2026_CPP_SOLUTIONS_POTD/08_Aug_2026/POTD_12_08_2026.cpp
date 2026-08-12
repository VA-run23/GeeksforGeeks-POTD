
// Adventure in a Maze

/*
 *    1. The problem asks to compute two values: 
 *       (a) total number of valid paths from top-left to bottom-right, 
 *       (b) maximum adventure value (sum of grid values along a valid path).
 *    2. Movement rules depend on cell values: 
 *       - 1 → can move right, 
 *       - 2 → can move down, 
 *       - 3 → can move both right and down.
 *    3. Use recursion with memoization (DP table) to avoid recomputation.
 *    4. totalPaths(i, j): counts paths modulo 1e9+7, exploring valid moves.
 *    5. maxAdventure(i, j): computes maximum sum along valid paths.
 *    6. Reset DP between the two computations since one stores counts, the other stores sums.
 *    7. Time Complexity: O(n²), Space Complexity: O(n²).
 */

class Solution {
public:
    const int mod = 1e9 + 7;

    int totalPaths(int i, int j, vector<vector<int>>& grid, int n,
                   vector<vector<int>>& dp) {
        if (i == n - 1 && j == n - 1) return dp[i][j] = 1;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (grid[i][j] != 2 && j + 1 < n) ans += totalPaths(i, j + 1, grid, n, dp);
        if (grid[i][j] != 1 && i + 1 < n) ans += totalPaths(i + 1, j, grid, n, dp);

        return dp[i][j] = ans % mod;
    }

    int maxAdventure(int i, int j, vector<vector<int>>& grid, int n,
                     vector<vector<int>>& dp) {
        if (i == n - 1 && j == n - 1) return dp[i][j] = grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int a = 0, b = 0;
        if (grid[i][j] != 2 && j + 1 < n) a = maxAdventure(i, j + 1, grid, n, dp);
        if (grid[i][j] != 1 && i + 1 < n) b = maxAdventure(i + 1, j, grid, n, dp);

        if (a == 0 && b == 0) return dp[i][j] = 0;
        return dp[i][j] = max(a, b) + grid[i][j];
    }

    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int paths = totalPaths(0, 0, grid, n, dp);

        for (auto& row : dp) fill(row.begin(), row.end(), -1);

        int maxAdv = maxAdventure(0, 0, grid, n, dp);

        return {paths, maxAdv};
    }
};

// Key Points
// 1. Two separate DP functions: one for path count, one for max sum.
// 2. Movement rules depend on cell values (1, 2, 3).
// 3. Memoization avoids recomputation of overlapping subproblems.
// 4. Reset DP between path count and max sum calculations.
// 5. Path count uses modulo 1e9+7.
// 6. Max adventure returns 0 if no valid path exists.
// 7. Runs in O(n²) time with O(n²) space.