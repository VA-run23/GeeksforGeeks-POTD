
/*
    1. This function scans the entire matrix 'mat' and stores coordinates of any element with a value of 0 in the vector 'zi'.
    2. The size of the matrix is determined using 'n = mat.size()' and 'm = mat[0].size()'.
    3. Every zero position '{i, j}' is pushed into 'zi' so that its entire row 'i' and column 'j' can be zeroed later.
    4. After collecting zero positions, the function loops through each pair '{row, col}' in 'zi'.
    5. It sets all elements in the row 'row' to 0 using a loop from 0 to 'm'.
    6. Similarly, it sets all elements in the column 'col' to 0 using a loop from 0 to 'n'.
    7. Time Complexity: O(n × m + x × (n + m)), where x is the number of zeros. Space Complexity: O(x) for storing zero positions.
*/

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<pair<int, int>> zi;
        int n = mat.size();
        int m = mat[0].size();


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    zi.push_back({i, j});
                }
            }
        }


        int x = zi.size();
        for (int j = 0; j < x; j++) {
            int row = zi[j].first;
            int col = zi[j].second;


            for (int i = 0; i < m; i++) {
                mat[row][i] = 0;
            }

   
            for (int i = 0; i < n; i++) {
                mat[i][col] = 0;
            }
        }
    }
};