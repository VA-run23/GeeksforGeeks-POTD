// Ways to Reach Origin

/*
 * Problem:
 *   - You are at point (x, y) on a grid.
 *   - You can move only left (x-1) or down (y-1).
 *   - Goal: Count the number of ways to reach (0,0).
 *
 * Approach:
 *   - Use DP table `paths[i][j]` = number of ways to reach (x,y) from (i,j).
 *   - Initialize base case: paths[x][y] = 1 (starting point).
 *   - Fill table backwards (from x,y down to 0,0).
 *   - Transition:
 *       paths[i][j] = paths[i+1][j] + paths[i][j+1]
 *   - Answer = paths[0][0].
 *
 * Complexity:
 *   - Time: O(x*y)
 *   - Space: O(x*y)
 */

class Solution {
  public:
    int ways(int x, int y) {
        int mod = 1e9 + 7;
        vector<vector<int>> paths(x + 1, vector<int>(y + 1, 0));

        // Base case: starting point
        paths[x][y] = 1;

        // Fill DP table backwards
        for (int i = x; i >= 0; --i) {
            for (int j = y; j >= 0; --j) {
                if (i + 1 <= x) paths[i][j] = (paths[i][j] + paths[i + 1][j]) % mod;
                if (j + 1 <= y) paths[i][j] = (paths[i][j] + paths[i][j + 1]) % mod;
            }
        }

        return paths[0][0];
    }
};