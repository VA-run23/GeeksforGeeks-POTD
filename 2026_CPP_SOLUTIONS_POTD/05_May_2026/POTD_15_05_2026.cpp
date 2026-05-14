// Special Keyboard

/*
 *    1. The problem involves maximizing the number of 'A's printed using a special keyboard.
 *    2. The keyboard has four operations: print 'A', select all, copy, and paste.
 *    3. For small values of n (≤ 6), the optimal solution is simply pressing 'A' repeatedly.
 *    4. For larger n, dynamic programming is used to calculate the maximum possible 'A's.
 *    5. The idea is to find the best breakpoint where copy-paste operations yield maximum growth.
 *    6. dp[i] stores the maximum number of 'A's achievable with i keystrokes.
 *    7. Time Complexity: O(n^2), Space Complexity: O(n).
 */

class Solution {
public:
    int optimalKeys(int n) {
        // code here
        if (n <= 6)
            return n;
        vector<long long> dp(n + 1, 1);
        for (int i = 1; i <= 6; i++)
            dp[i] = i;
        for (int i = 7; i <= n; i++) {
            for (int j = i - 3; j > 0; j--) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};

// Key Points
// 1. For n ≤ 6, pressing 'A' is optimal.
// 2. Beyond 6, copy-paste sequences outperform single presses.
// 3. Dynamic programming ensures subproblem reuse.
// 4. Breakpoints are chosen where copy-paste yields maximum multiplication.
// 5. dp[j] represents the best result achievable with j keystrokes.
// 6. The formula dp[i] = max(dp[j] * (i - j - 1)) captures optimal growth.
// 7. Complexity is quadratic, but efficient enough for typical constraints.