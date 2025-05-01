/*
This code gives the nth row of Pascal's Triangle:
1. A 2D vector `pasTri` is initialized to hold all rows of Pascal's Triangle up to row `n`.
2. Each row's size is dynamically set using `.resize(i+1)` to ensure proper dimensions.
3. The first and last elements of every row are set to 1, as per Pascal's Triangle's definition.
4. For intermediate elements, the sum of two numbers from the previous row is computed and stored.
5. The loop runs up to `n`, iterating row by row, calculating values based on the previous row.
6. Finally, the nth row (at index `n-1`) is returned, as vector indices are 0-based in C++.
7. Time Complexity: O(n^2), as every element of the triangle up to row `n` is computed.
   Space Complexity: O(n^2), since a 2D vector is used to store all rows of the triangle.
*/


class Solution {
    public:
      vector<int> nthRowOfPascalTriangle(int n) {
          // code here
          vector<vector<int>> pasTri(n);
  
          for (int i = 0; i < n; i++) {
              pasTri[i].resize(i + 1);
              pasTri[i][0] = pasTri[i][i] = 1;
  
              for (int j = 1; j < i; j++) {
                  pasTri[i][j] = pasTri[i - 1][j - 1] + pasTri[i - 1][j];
              }
          }
  
          return pasTri[n-1];
      }
  };