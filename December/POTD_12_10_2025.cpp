/*
    1. The function `transpose` takes a square matrix (vector of vectors) as input and returns its transpose.
    2. It first calculates the size `n` of the matrix, which represents both rows and columns since it's square.
    3. The outer loop runs from `i = 0` to `n-1`, iterating over rows.
    4. The inner loop runs from `j = i` to `n-1`, ensuring each pair (i, j) is swapped only once to avoid redundant swaps.
    5. Inside the loop, elements `mat[i][j]` and `mat[j][i]` are swapped using a temporary variable `temp`.
    6. This effectively converts rows into columns and columns into rows, achieving the transpose in-place.
    7. Finally, the modified matrix is returned. 
    - Time Complexity: O(n^2), since every element in the upper triangle is visited once.
    - Space Complexity: O(1), as the transpose is done in-place without extra storage.
*/

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int temp = mat[j][i];
                mat[j][i] = mat[i][j];
                mat[i][j] = temp;
            }
        }
        return mat;
    }
};