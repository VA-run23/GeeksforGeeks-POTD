// Longest Possible Route in a Matrix with Hurdles

/*
 *    1. The problem asks for the longest path from a source to a destination in a matrix with hurdles.
 *    2. Movement is allowed in four directions (up, down, left, right).
 *    3. Cells with value 0 are hurdles and cannot be traversed.
 *    4. Use DFS with backtracking to explore all possible paths.
 *    5. Mark cells as visited during traversal and unmark them when backtracking.
 *    6. Track the maximum path length found while exploring.
 *    7. Time Complexity: O(4^(n*m)) in worst case, Space Complexity: O(n*m) for visited matrix.
 */

class Solution {
  public:
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};
    
    int svc(int i, int j, vector<vector<int>> &mat, int xd, int yd, vector<vector<bool>> &vis, int &lg) {
        if (i == xd && j == yd)
            return 0;
        vis[i][j] = true;
        
        int ans = -100000000;
        
        for (int k = 0; k<4; k++) {
            int ni = i + dirX[k];
            int nj = j + dirY[k];
            
            if (ni<0 || nj<0 || (ni >= (mat.size())) || (nj >= (mat[0].size())) || (mat[ni][nj] == 0) || (vis[ni][nj]))
                continue;
            
            ans = max(ans, 1 + svc(ni, nj, mat, xd, yd, vis, lg));
            lg = max(lg, ans);
        }
        
        vis[i][j] = false;
        return ans;
    }
    
    int longestPath(vector<vector<int>> & mat, int xs, int ys, int xd, int yd) {
        // code here 
        int n = mat.size();
        int m = mat[0].size();
        
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return - 1;
        
        int lg = -1;
        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
        
        int nt = svc(xs, ys, mat, xd, yd, vis, lg);
        return max(lg, nt);
    }
};

// Key Points
// 1. DFS with backtracking explores all possible paths.
// 2. Hurdles (0s) block traversal.
// 3. Visited matrix prevents revisiting cells in the same path.
// 4. Backtracking ensures exploration of alternate routes.
// 5. Maximum path length is updated during recursion.
// 6. If source or destination is blocked, return -1.
// 7. Exponential time complexity due to exhaustive search.