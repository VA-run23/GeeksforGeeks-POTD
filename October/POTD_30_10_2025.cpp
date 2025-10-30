/*
    1. The problem is to flip all 'O's that are fully surrounded by 'X's into 'X', while keeping boundary-connected 'O's unchanged.
    2. The dfs() function marks all 'O's connected to a boundary 'O' as visited (safe) using depth-first search in 4 directions.
    3. In fill(), we create a visited matrix to track which 'O's are safe and should not be flipped.
    4. We traverse the first row, last row, first column, and last column (the boundary) and run dfs() from any 'O' found there.
    5. This ensures that all 'O's connected to the boundary are marked safe, even if they are deep inside the grid.
    6. After marking, we scan the entire grid: any 'O' not visited is surrounded and thus flipped to 'X'.
    7. Time Complexity: O(n*m) since each cell is visited at most once; Space Complexity: O(n*m) for the visited matrix and recursion stack.
*/

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj] && grid[ni][nj] == 'O') {
                dfs(ni, nj, grid, vis);
            }
        }
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O' && !vis[i][0]) dfs(i, 0, grid, vis);
            if (grid[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, grid, vis);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O' && !vis[0][j]) dfs(0, j, grid, vis);
            if (grid[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1, j, grid, vis);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !vis[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
