// Rat Maze With Multiple Jumps

/*
 *    1. The problem involves finding a path in a maze where each cell indicates maximum jump length.
 *    2. The rat can move either right or down from a given cell.
 *    3. The goal is to reach the destination cell (n-1, n-1) starting from (0,0).
 *    4. A recursive backtracking approach is used to explore possible paths.
 *    5. The solution marks visited cells and backtracks if a path fails.
 *    6. If a valid path is found, the matrix of the path is returned; otherwise, -1 is returned.
 *    7. Time Complexity: O(n^2) in worst case due to backtracking; Space Complexity: O(n^2) for recursion stack and auxiliary matrices.
 */

class Solution {
  public:
    void solve(vector<vector<int>>& mat, vector<vector<int>>& ans, int n, int m,
               int u, int v, bool& bl, vector<vector<int>>& v2) {
        int a = mat[u][v];
        ans[u][v] = 1;
        v2[u][v] = 1;
        if (u == n - 1 && v == m - 1) {
            bl = true;
            return;
        }
        int i = v + 1;
        int j = u + 1;
        int cnt = 0;
        while ((i < m && i <= v + a) && (j < n && j <= u + a)) {
            if (cnt % 2 == 0) {
                if (((u == n - 1 && i == n - 1) || mat[u][i] != 0) &&
                    v2[u][i] == 0) {
                    solve(mat, ans, n, m, u, i, bl, v2);
                    if (bl) {
                        return;
                    }
                }
                i++;
            } else {
                if (((j == n - 1 && v == n - 1) || mat[j][v] != 0) &&
                    v2[j][v] == 0) {
                    solve(mat, ans, n, m, j, v, bl, v2);
                    if (bl) {
                        return;
                    }
                }
                j++;
            }
            cnt++;
        }
        while (i < m && i <= v + a) {
            if (((u == n - 1 && i == n - 1) || mat[u][i] != 0) &&
                v2[u][i] == 0) {
                solve(mat, ans, n, m, u, i, bl, v2);
                if (bl) {
                    return;
                }
            }
            i++;
        }
        while (j < n && j <= u + a) {
            if (((j == n - 1 && v == n - 1) || mat[j][v] != 0) &&
                v2[j][v] == 0) {
                solve(mat, ans, n, m, j, v, bl, v2);
                if (bl) {
                    return;
                }
            }
            j++;
        }
        ans[u][v] = 0;
        return;
    }
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> v2(n, vector<int>(n, 0));
        int u = 0;
        int v = 0;
        bool bl = false;
        solve(mat, ans, n, n, u, v, bl, v2);
        if (ans[n - 1][n - 1] == 1) {
            return ans;
        }
        vector<vector<int>> ans1;
        vector<int> v1;
        v1.push_back(-1);
        ans1.push_back(v1);
        return ans1;
    }
};

// Key Points
// 1. Each cell value represents maximum jump length.
// 2. Rat can move only right or down.
// 3. Backtracking ensures exploration of all possible paths.
// 4. Auxiliary matrix prevents revisiting cells.
// 5. If destination is reached, path matrix is returned.
// 6. If no path exists, return -1.
// 7. Complexity is exponential in worst case but pruned by jump limits.