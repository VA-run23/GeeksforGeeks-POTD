// Minimum Steps by Knight

/*
 * Problem:
 *   - Given a knight’s position and a target position on an n x n chessboard.
 *   - Find the minimum number of moves required for the knight to reach the target.
 *
 * Approach:
 *   - Use BFS since each move has equal cost.
 *   - Track visited cells to avoid revisiting.
 *   - Stop when target is reached.
 *
 * Complexity:
 *   - Time: O(n^2) (each cell visited at most once).
 *   - Space: O(n^2) for visited array.
 */

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Knight’s possible moves
        vector<vector<int>> dir = {
            {-2,-1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
        };
        
        int x1 = knightPos[0], y1 = knightPos[1];
        int x2 = targetPos[0], y2 = targetPos[1];

        if (x1 == x2 && y1 == y2) return 0;

        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        vis[x1 - 1][y1 - 1] = true;
        q.push({x1, y1, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int cx = curr[0], cy = curr[1], dist = curr[2];

            for (auto& d : dir) {
                int nx = cx + d[0], ny = cy + d[1];
                if (isSafe(nx, ny, n) && !vis[nx - 1][ny - 1]) {
                    if (nx == x2 && ny == y2) return dist + 1;
                    q.push({nx, ny, dist + 1});
                    vis[nx - 1][ny - 1] = true;
                }
            }
        }
        return -1; // unreachable (shouldn’t happen on chessboard)
    }

  private:
    bool isSafe(int x, int y, int n) {
        return (x > 0 && y > 0 && x <= n && y <= n);
    }
};