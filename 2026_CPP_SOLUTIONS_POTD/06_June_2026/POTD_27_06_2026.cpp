// Count the Number of Ways to Tile the Floor

/*
 *    1. The problem is to count ways to tile a floor of size n x m using tiles of size 1 x m.
 *    2. A tile can be placed vertically (occupying 1 x m) or horizontally (occupying m x 1).
 *    3. If placed vertically, the remaining subproblem reduces to size (n-1).
 *    4. If placed horizontally, the remaining subproblem reduces to size (n-m).
 *    5. This forms a recurrence relation: ways(n) = ways(n-1) + ways(n-m).
 *    6. Dynamic programming is used to avoid recomputation and handle large n efficiently.
 *    7. Time Complexity: O(n), Space Complexity: O(n+m).
 */

class Solution {
    public:
    int countWays(int n, int m) {
        // code here.
        vector<int>dp(n + m+1, 0);
        
        const int mod = (int)(1e9) + 7;
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = (dp[i + 1]%mod + dp[i + m]%mod)%mod;
        }
        return dp[0];
    }
};

// Key Points
// 1. Problem reduces to recurrence relation ways(n) = ways(n-1) + ways(n-m).
// 2. Vertical placement reduces problem size by 1.
// 3. Horizontal placement reduces problem size by m.
// 4. Dynamic programming ensures efficient computation.
// 5. Modulo 1e9+7 is used to handle large results.
// 6. Bottom-up DP avoids stack overflow compared to recursion.
// 7. Space optimization possible by storing only last m states.