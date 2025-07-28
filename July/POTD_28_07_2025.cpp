/*
    1. Compute row and column sums for each index 'i' and track the maximum row sum ('maxrv') and maximum column sum ('maxcv').
    2. For each row 'i', sum its values and update 'maxrv' using: maxrv = max(maxrv, rowVal).
    3. For each column 'i', sum its values and update 'maxcv' using: maxcv = max(maxcv, colVal).
    4. Determine the highest target sum a beautiful matrix would have: maxi = max(maxrv, maxcv) * n.
    5. Traverse the entire matrix and compute the actual sum of all elements in 'matSum'.
    6. The difference (maxi - matSum) is the minimum number of +1 operations needed to make every row and column equal in sum.
    7. Time Complexity: O(n²) for two nested loops; Space Complexity: O(1) since no extra space is used beyond variables.

💡 Key Point:
In a square matrix, if the sum of elements across every "column" is equal, then it "must" also be equal across every "row", and vice versa. 
This is due to the inherent symmetry of square matrices—where row and column totals both represent the same grand total, just viewed from different angles.
*/

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int maxcv = 0, maxrv = 0;
        int rowVal = 0, colVal = 0;
        
        for(int i = 0; i<n; i++){
            rowVal = 0;
            colVal = 0;
            for(int j = 0; j<n; j++){
                rowVal +=mat[i][j];
            }
            
            for(int k = 0; k<n; k++){
                colVal += mat[k][i];
            }
            maxcv = max(maxcv, colVal);
            maxrv = max(maxrv, rowVal);
            
        }
        
        int maxi = max(maxcv, maxrv) * n;
        int matSum =0;
        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                matSum += mat[i][j];
            }
        }
        
        return maxi - matSum;
        
    }
};