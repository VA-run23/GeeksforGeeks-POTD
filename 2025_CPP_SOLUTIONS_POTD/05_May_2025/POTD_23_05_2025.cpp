/* 
    This function calculates the number of ways to achieve sum 'x' using 'n' dice with 'm' faces.
    1. We initialize a DP table where dp[i][j] represents ways to get sum 'j' with 'i' dice.
    2. Base case: With one die, only values between 1 to 'm' can be formed directly.
    3. We iterate over dice count, updating possible sums using previous values.
    4. For each sum, we add up ways from previous dice rolls, considering all face values.
    5. This ensures we account for all possible dice combinations efficiently.
    6. The final result is stored at dp[n][x], representing ways to achieve sum 'x' using 'n' dice.
    7. The approach follows dynamic programming principles to optimize recursive calculations.
*/

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
        // code here
        for (int i = 1; i <= m && i <= x; i++) {
            dp[1][i] = 1;
        }

        for (int dice = 2; dice <= n; dice++) {
            for (int sum = 1; sum <= x; sum++) {
                for (int face = 1; face <= m; face++) {
                    if (sum - face >= 0) {
                        dp[dice][sum] += dp[dice-1][sum-face];
                    }
                }
            }
        }

        return dp[n][x];
    }
};
