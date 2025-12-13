/*
   1. The function 'swapDiagonal' takes a square matrix (2D vector) as input by reference.
   2. It first calculates the size 'n' of the matrix using 'mat.size()'.
   3. A loop runs from 'i = 0' to 'i < n', iterating through each row of the matrix.
   4. For each row, it stores the element of the major diagonal ('mat[i][i]') in a temporary variable.
   5. It then replaces the major diagonal element with the corresponding minor diagonal element ('mat[i][n-i-1]').
   6. Finally, the minor diagonal element is updated with the value stored in 'temp', effectively swapping both diagonals.
   7. After completing the loop, all major diagonal elements are swapped with their corresponding minor diagonal elements.
      → Time Complexity: O(n), since we iterate through each row once.
      → Space Complexity: O(1), as only a temporary variable is used for swapping.
*/

class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        for(int i = 0; i<n; i++){
            int temp = mat[i][i];
            mat[i][i] = mat[i][n-i-1];
            mat[i][n-i-1]= temp;
        }
        return;
    }
};
