/*
1. Initialize a vector `dp` of size `sum + 1` with all elements as `0`, representing the number of ways to make each sum, and set `dp[0] = 1` (there is one way to make sum 0—by using no coins).

2. Loop through each coin in the `coins` array to consider its contributions to different sums.

3. For each coin, iterate through all sums `j` from the value of the coin up to `sum`, as smaller sums cannot include this coin.

4. Use the transition relation `dp[j] += dp[j - coin]`, meaning the number of ways to make sum `j` increases by the number of ways to make the sum `j - coin` (adding this coin).

5. Repeat this for all coins, updating the `dp` table to include the cumulative count of ways to make each sum.

6. By the end of the iterations, `dp[sum]` contains the total number of ways to make the target sum using the given coins.

7. Return `dp[sum]` as the final result, indicating the total number of ways to make the target sum using combinations of coins.
*/

class Solution {
public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int> dp(sum + 1, 0); 
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[sum];
    }
};