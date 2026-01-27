/*
    1. This code solves the Word Search problem using Depth-First Search (DFS) with backtracking.  
    2. The 'dfs' function recursively explores all four directions (up, down, left, right) to match characters of the word.  
    3. A 'vis' matrix is used to mark visited cells to avoid revisiting during the current path.  
    4. The search starts from every cell that matches the first character of the word.  
    5. If the entire word is matched ('ind == word.size()'), the function returns true.  
    6. Time Complexity: O(N * M * 4^L), where N×M is grid size and L is word length.  
    7. Space Complexity: O(N * M) for the visited matrix plus recursion stack of depth L.  
*/

class Solution {
public:
    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};
    bool dfs(int ind, int row, int col, vector<vector<char>>& mat, int n, int m,
             string& word, vector<vector<int>>& vis) {
        if (ind == word.size())
            return true;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                mat[nRow][nCol] == word[ind] && vis[nRow][nCol] == -1) {
                vis[nRow][nCol] = 1;
                if (dfs(ind + 1, nRow, nCol, mat, n, m, word, vis))
                    return true;
                vis[nRow][nCol] = -1;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(1, i, j, mat, n, m, word, vis))
                        return true;
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};

/* Key points:
- The algorithm uses DFS + backtracking to explore possible paths.
- Each cell can be visited only once in a given path (tracked by 'vis').
- Starting points are cells matching the first character of the word.
- Backtracking ensures that failed paths are undone for fresh exploration.
- Time complexity grows exponentially with word length due to branching factor.
- Space complexity is mainly due to the visited matrix and recursion depth.
- This is a brute-force but effective approach for grid-based word search problems.
*/
