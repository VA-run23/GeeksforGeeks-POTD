// 1s Surrounded by 0s

/*
 *    1. The problem requires counting 1s that are not connected to the boundary.
 *    2. We use DFS to mark all 1s connected to the boundary as visited.
 *    3. Boundary traversal ensures we eliminate all 1s touching edges.
 *    4. After DFS, remaining 1s are those completely surrounded by 0s.
 *    5. We iterate through the grid to count unvisited 1s.
 *    6. DFS ensures connected components are fully explored.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m) due to recursion stack.
 */

class Solution {
    int n, m;

private:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 2;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& d : dir) {
            int nr = row + d[0], nc = col + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                dfs(grid, nr, nc);
            }
        }
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);

            if (grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);

            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cnt++;
            }
        return cnt;
    }
};

// Key Points
// 1. DFS is used to mark boundary-connected 1s.
// 2. Only interior 1s remain unmarked after DFS.
// 3. Traversing boundaries first ensures correctness.
// 4. Recursion stack may grow up to O(n*m).
// 5. Works efficiently for large grids.
// 6. Simple to implement with DFS.
// 7. Alternative methods exist using BFS or Union-Find.