/*
    1. This code solves Matrix Chain Multiplication using DP to find the minimum cost parenthesization of matrices.
    2. dp[i][j] stores the minimum multiplication cost for matrices from index i to j.
    3. split[i][j] stores the index k where the optimal split occurs for reconstructing the parenthesization.
    4. The loops try all chain lengths and all possible splits to compute optimal costs.
    5. The cost formula arr[i] * arr[k+1] * arr[j+1] represents scalar multiplications for a chosen split.
    6. After DP fills, build() recursively reconstructs the optimal parenthesization using the split table.
    7. Time Complexity: O(n³), Space Complexity: O(n²), where n = number of matrices.
*/

class Solution {
    
private:
    string build(int i, int j, vector<vector<int>> &split) {
        if (i == j) return string(1, 'A' + i);
        int k = split[i][j];
        return "(" + build(i, k, split) + build(k + 1, j, split) + ")";
    }
    
public:
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n = arr.size();
        int m = n - 1; 
        vector<vector<long long>> dp(m, vector<long long>(m, 0));
        vector<vector<int>> split(m, vector<int>(m, -1));
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i + len - 1 < m; i++) {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;
                
                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + 1LL * arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }
        
        return build(0, m - 1, split);
    }
};