/*
   1. The code builds a 2D prefix sum matrix 'pre' where each cell (i,j) stores the sum of all elements 
      from the top-left (0,0) to (i,j), using inclusion-exclusion to avoid double counting.
   2. For each element in 'mat', it adds values from the top and left neighbors, subtracting the overlap 
      at (i-1, j-1) to correctly compute cumulative sums.
   3. Once the prefix matrix is built, queries of the form [r1, c1, r2, c2] are answered in O(1) time 
      using the inclusion-exclusion principle on the 'pre' matrix.
   4. The sum of a submatrix is calculated as: pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1], 
      carefully checking boundaries when r1 or c1 equals 0.
   5. Each query result is stored in the 'ans' vector, which is returned at the end containing all submatrix sums.
   6. Time Complexity: Building the prefix sum matrix takes O(n*m), and answering q queries takes O(q), 
      so total = O(n*m + q).
   7. Space Complexity: The prefix sum matrix requires O(n*m) extra space, and the result vector requires O(q).
*/

// Key Points:
// - Prefix sum matrix allows submatrix sum queries in O(1) time.
// - Inclusion-exclusion principle ensures no double counting.
// - Boundary checks (r1=0 or c1=0) are crucial to avoid invalid indices.
// - Efficient for multiple queries compared to brute force O(n*m) per query.

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> pre(n,vector<int>(m,0));

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                pre[i][j]=mat[i][j];
                
                if(i>0){
                    pre[i][j]+=pre[i-1][j];
                }
                if(j>0){
                    pre[i][j]+=pre[i][j-1];
                }
                if (i>0 && j>0){
                    pre[i][j]-=pre[i-1][j-1];
                }
            }
        }

       
        vector<int> ans;
        
        for (auto &q : queries) {
            
            int r1=q[0], c1=q[1];
            int r2=q[2], c2=q[3];

            int sum=pre[r2][c2];
            
            if (r1>0){
                sum-=pre[r1-1][c2];
            }
            
            if (c1>0){
                sum-=pre[r2][c1-1];
            }
            
            if (r1>0 && c1>0){
                sum+=pre[r1-1][c1-1];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};