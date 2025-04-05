/*
   1. This code implements Depth-First Search (DFS) to count the number of islands in a grid.
   2. The dfs function explores all connected land cells ('L') and marks them visited ('W').
   3. It recursively checks all 8 possible directions (vertical, horizontal, and diagonal).
   4. The countIslands function iterates through the grid to find unvisited land cells.
   5. Whenever a new island ('L') is found, it increments the island count and calls dfs.
   6. The dfs function ensures all land cells within the island are marked as visited.
   7. After processing all cells, countIslands returns the total number of islands.
*/

class Solution {
    public:
        void dfs(vector<vector<char>>& grid, int i, int j) {
            int row = grid.size();
            int col = grid[0].size();
    
            if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 'W') 
                return;
    
            grid[i][j] = 'W';
    
            dfs(grid, i - 1, j); // Up
            dfs(grid, i + 1, j); // Down
            dfs(grid, i, j - 1); // Left
            dfs(grid, i, j + 1); // Right
            dfs(grid, i + 1, j + 1); // Bottom-right diagonal
            dfs(grid, i - 1, j - 1); // Top-left diagonal
            dfs(grid, i + 1, j - 1); // Bottom-left diagonal
            dfs(grid, i - 1, j + 1); // Top-right diagonal
        }
    
        int countIslands(vector<vector<char>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int ans = 0;
    
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 'L') { // Found a new island
                        ans++;
                        dfs(grid, i, j); // Mark the entire island as visited
                    }
                }
            }
            
            return ans;
        }
    };