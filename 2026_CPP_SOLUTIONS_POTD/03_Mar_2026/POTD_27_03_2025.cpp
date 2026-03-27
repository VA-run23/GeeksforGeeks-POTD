// Chocolates Pickup Problem

/*
 *    1. Two players start at the top row, one at column 0 and the other at column m-1.
 *    2. Both players move down simultaneously, each step allowing movement to adjacent columns.
 *    3. At each row, they collect chocolates from their respective positions.
 *    4. If both land on the same cell, chocolates are counted only once.
 *    5. The goal is to maximize the total chocolates collected until reaching the last row.
 *    6. Dynamic programming is used to track states of both players across rows.
 *    7. Time Complexity: O(n * m^2 * 9), Space Complexity: O(m^2) using rolling arrays.
 */

class Solution {
  public:
    int maxChocolate(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(m, 0)), next(m, vector<int>(m, 0));
        for(int r = n - 1; r >= 0; r--) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = 0; c2 < m; c2++) {
                    curr[c1][c2] = -1e9;
                    for(int u = -1; u <= 1; u++) {
                        for(int v = -1; v <= 1; v++) {
                            if(c1 + u < 0 || c1 + u >= m || c2 + v < 0 || c2 + v >= m) continue;
                            curr[c1][c2] = max(curr[c1][c2], grid[r][c1] + ((c1 == c2) ? 0 : grid[r][c2]) + next[c1 + u][c2 + v]);
                        }
                    }
                }
            }
            next = curr;
        }
        return next[0][m - 1];
    }
};

// Key Points
// 1. Two players move simultaneously from top to bottom.
// 2. Each player can move diagonally left, straight down, or diagonally right.
// 3. Chocolates are collected from both positions unless overlapping.
// 4. DP state is defined by row and both column positions.
// 5. Rolling arrays optimize space from O(n * m^2) to O(m^2).
// 6. Transition considers all 9 possible moves (3 for each player).
// 7. Final answer is the maximum chocolates collected when reaching the bottom row.
