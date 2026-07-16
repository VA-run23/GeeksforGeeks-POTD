// Count of N-digit Numbers with Given Digit Sum

/*
 *    1. The problem asks for the number of N-digit numbers whose sum of digits equals a given target sum.
 *    2. Use recursion with memoization (DP) to explore all digit combinations.
 *    3. Start with the first digit (1–9) to ensure the number has N digits and doesn’t begin with zero.
 *    4. For each recursive step, add digits from 0–9 and reduce the remaining sum accordingly.
 *    5. Memoize results in a DP table to avoid recomputation and improve efficiency.
 *    6. Base case: when count of digits equals N, check if the sum matches the target.
 *    7. Time Complexity: O(n * sum * 10), Space Complexity: O(n * sum).
 */

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int n, int sum, int cnt, int sum1) {
        if (cnt == n) {
            if (sum == sum1) {
                return dp[cnt][sum1] = 1;
            }
            else {
                return dp[cnt][sum1] = 0;
            }
        }
        if (dp[cnt][sum1] != -1) {
            return dp[cnt][sum1];
        }
        int a = 0;
        for (int j = 0; j <= 9; j++) {
            a += solve(n, sum, cnt + 1, sum1 + j);
        }
        return dp[cnt][sum1] = a;
    }
    int countWays(int n, int sum) {
        // code here
        dp.assign(n + 1, vector<int>(8101, -1));
        int b = 0;
        for (int i = 1; i <= 9; i++) {
            int cnt = 1;
            int sum1 = i;
            b += solve(n, sum, cnt, sum1);
        }
        if (b == 0) {
            return -1;
        }
        return b;
    }
};

// Key Points
// 1. Recursion explores all possible digit combinations.
// 2. DP memoization avoids redundant calculations.
// 3. First digit restricted to 1–9 to ensure valid N-digit numbers.
// 4. Each recursive call adds one digit and updates sum.
// 5. Base case checks if digit count equals N and sum matches target.
// 6. Returns -1 if no valid number exists.
// 7. Efficient solution leveraging recursion + memoization.