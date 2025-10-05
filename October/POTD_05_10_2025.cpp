/*
    1. This code solves the "Rat in a Maze" problem using recursive backtracking to find all valid paths from (0,0) to (n-1,n-1) in a grid.
    2. The helper function explores all four directions (Down, Up, Right, Left) from each cell, avoiding blocked cells and revisits.
    3. The vis[][] matrix tracks visited cells to prevent cycles during path exploration and is reset during backtracking.
    4. If the destination cell is reached, the current path string is added to the answer list.
    5. The ratInMaze() function initializes the visited matrix and starts the recursion only if the starting cell is open.
    6. After collecting all valid paths, the result is sorted lexicographically before returning.
    7. Time Complexity: O(4^(n²)) in worst case; Space Complexity: O(n²) for recursion stack and visited matrix.
*/

class Solution {
private:
    void helper(int row, int col, int n, string curr, vector<string>& ans,
                vector<vector<int>>& maze, vector<vector<int>>& vis) {
                    
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || vis[row][col] == 1)
            return;
        if (row == n - 1 && col == n - 1) {
            ans.push_back(curr);
            return;
        }
        
        vis[row][col] = 1;
        helper(row + 1, col, n, curr + "D", ans, maze, vis);
        helper(row - 1, col, n, curr + "U", ans, maze, vis);
        helper(row, col + 1, n, curr + "R", ans, maze, vis);
        helper(row, col - 1, n, curr + "L", ans, maze, vis);
        vis[row][col] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        if (maze[0][0] == 1)
            helper(0, 0, n, "", ans, maze, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
