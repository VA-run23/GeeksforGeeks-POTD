/*
    1. This function calculates the minimum number of perfect squares that sum up to a given number `n`.
    2. It uses dynamic programming with a `dp` array where `dp[i]` stores the minimum number of squares summing to `i`.
    3. The array is initialized with `INT_MAX` to represent infinity, except `dp[0] = 0` as base case.
    4. For each number `i` from 1 to `n`, it checks all perfect squares `j*j` less than or equal to `i`.
    5. It updates `dp[i]` by choosing the minimum between its current value and `dp[i - j*j] + 1`.
    6. This ensures that for every `i`, we find the optimal number of squares needed to reach it.
    7. Time Complexity: O(n√n), Space Complexity: O(n) — due to nested loops and the `dp` array.
*/

class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {  
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
    
        return dp[n];
    }
};