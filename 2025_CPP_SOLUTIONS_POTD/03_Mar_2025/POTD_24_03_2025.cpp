/*
1. The function calculates the minimum cost of matrix chain multiplication using dynamic programming.
2. `dp[i][j]` stores the minimum cost to multiply matrices from index `i` to `j` in the array.
3. The outer loop iterates over possible chain lengths (`len`), starting from 2, as a single matrix requires no multiplication.
4. The second loop iterates over the starting index `i`, and the end index `j` is calculated as `i + len - 1`.
5. For each `i` and `j`, the minimum cost is computed by dividing the chain at every possible index `k`.
6. The cost is computed as the sum of costs for two subchains plus the cost of multiplying their results.
7. Finally, `dp[1][n-1]` holds the minimum cost to multiply all matrices, which is returned.
*/

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n-1];
    }
};