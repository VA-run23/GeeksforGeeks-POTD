// Coverage of all Zeros in a Binary Matrix

/*
 *    1. The problem requires counting zeros covered by at least one '1' in each row and column.
 *    2. Coverage is checked in four directions: left-to-right, right-to-left, top-to-bottom, bottom-to-top.
 *    3. For each direction, once a '1' is found, subsequent zeros are considered covered.
 *    4. The algorithm iterates through rows and columns separately to ensure full coverage.
 *    5. A counter accumulates the number of covered zeros across all directions.
 *    6. The final result is returned as the total coverage count.
 *    7. Time Complexity: O(n*m), Space Complexity: O(1).
 */

class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int cov = 0;
        

        for(int i = 0; i < n; i++) {
            bool fndOne = false;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) fndOne = true;
                else {
                    if(fndOne) cov++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            bool fndOne = false;
            for(int j = m-1; j >= 0; j--) {
                if(mat[i][j] == 1) fndOne = true;
                else {
                    if(fndOne) cov++;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            bool fndOne = false;
            for(int j = 0; j < n; j++) {
                if(mat[j][i] == 1) fndOne = true;
                else {
                    if(fndOne) cov++;
                }
            }
        }
        
        
        for(int i = 0; i < m; i++) {
            bool fndOne = false;
            for(int j = n-1; j >= 0; j--) {
                if(mat[j][i] == 1) fndOne = true;
                else {
                    if(fndOne) cov++;
                }
            }
        }
        
        return cov;
    }
};

// Key Points
// 1. Coverage is determined by scanning in four directions.
// 2. Each zero is counted only if preceded by a '1' in that direction.
// 3. Rows are scanned left-to-right and right-to-left.
// 4. Columns are scanned top-to-bottom and bottom-to-top.
// 5. Boolean flag tracks whether a '1' has been encountered.
// 6. Counter accumulates covered zeros across all scans.
// 7. Efficient O(n*m) solution with constant extra space.