/*
    1. Iterate over each index `i` from 0 to n-1, computing `rowVal` and `colVal` as the sum of the ith row and ith column respectively.
    2. Within the inner loop, increment `rowVal` with `mat[i][j]`, `colVal` with `mat[j][i]`, and add `mat[i][j]` to the total matrix sum `matSum`.
    3. After processing each row and column, update `maxval` as the maximum of `maxval`, `rowVal`, and `colVal`.
    4. After finishing all iterations, `maxval` holds the highest sum found across any row or column.
    5. Multiply `maxval` by `n` to compute the ideal total sum required if every row and column matched this maximum.
    6. Subtract the current `matSum` from this ideal sum to get the minimum number of +1 operations needed to make the matrix beautiful.
    7. Time Complexity: O(n²) — full matrix traversal; Space Complexity: O(1) — uses only scalar variables without extra space.
*/

/*💡
    Key Point:
    In a square matrix, if the sum of elements across every "column" is equal, then it "must" also be equal across every "row", and vice versa. 
    This is due to the inherent symmetry of square matrices—where row and column totals both represent the same grand total, just viewed from different angles.
*/

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int maxval =0, matSum =0;
        int rowVal = 0, colVal = 0;
        
        for(int i = 0; i<n; i++){
            rowVal = 0;
            colVal = 0;
            for(int j = 0; j<n; j++){
                rowVal +=mat[i][j];
                colVal += mat[j][i];
                matSum += mat[i][j];
            }
            maxval = max(maxval, max(rowVal, colVal));
            
        }
        
        maxval *= n;

        return maxval - matSum;
        
    }
};