/* 
    1. Extract the grid dimensions and check if the start or destination cell is blocked.
    2. Initialize a DP table where dp[i][j] holds the number of ways to reach cell (i, j).
    3. Begin iterating through the grid row by row and column by column.
    4. If a cell contains '1' (blocked), skip it as it cannot be part of any path.
    5. If reachable from above, add the number of paths from the top cell to dp[i][j].
    6. If reachable from the left, add the number of paths from the left cell to dp[i][j].
    7. The final answer is stored in dp[n-1][m-1], which represents the total unique paths.
*/

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here        
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0; 
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue; 
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1]; 
            }
        }
        
        return dp[n-1][m-1]; 
    }
};
