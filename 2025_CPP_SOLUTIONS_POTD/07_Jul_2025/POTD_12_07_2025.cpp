
/*
    1. This code solves the Gold Mine Problem, where a miner collects maximum gold starting from any cell in the first column and moving rightward (→, ↗, ↘).
    2. A 2D vector 'maxT' stores the maximum gold collectible at each cell, initializing its first column directly from 'mat'.
    3. For each cell in columns 1 to n-1, the value is updated by adding 'mat[i][j]' to the max of three possible predecessors: left, left-up, and left-down.
    4. Boundary conditions ensure the indices don't go out of bounds while accessing diagonal cells.
    5. After processing all columns, the maximum value in the last column of 'maxT' gives the final result.
    6. This solution uses dynamic programming to propagate optimal sub-solutions across the grid.
    7. Time Complexity: O(m * n); Space Complexity: O(m * n), where 'm' and 'n' are the grid dimensions.
*/

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> maxT(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            maxT[i][0] = mat[i][0];
        }

        for(int j = 1; j < n; j++) {
            for(int i = 0; i < m; i++) {
                int maxPrev = 0;
                if(i > 0 && j > 0) {
                    maxPrev = max(maxPrev, maxT[i - 1][j - 1]);
                }
                if(j > 0) {
                    maxPrev = max(maxPrev, maxT[i][j - 1]);
                }
                if(i < m - 1 && j > 0) {
                    maxPrev = max(maxPrev, maxT[i + 1][j - 1]);
                }
                maxT[i][j] = mat[i][j] + maxPrev;
            }
        }

        int result = 0;
        for(int i = 0; i < m; i++) {
            result = max(result, maxT[i][n - 1]);
        }

        return result;
    }
};