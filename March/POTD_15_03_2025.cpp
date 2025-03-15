/*
1. Define a vector `dp` of size `sum + 1` initialized to `INT_MAX` to represent the minimum number of coins required to form each sum, and set `dp[0] = 0` (no coins needed to make sum 0).
2. Loop through each coin in the array and for each coin, iterate through sums from `coin` to `sum`.
3. Check if the current sum (`j - coin`) can be formed (i.e., `dp[j - coin]` is not `INT_MAX`).
4. If the current sum can be formed, update `dp[j]` with the minimum of its current value and `dp[j - coin] + 1` (the count when including this coin).
5. This ensures that `dp[j]` contains the minimum number of coins needed to form sum `j` using the given coins.
6. After filling the DP array, check the value at `dp[sum]`; if it's `INT_MAX`, return `-1` (sum cannot be formed), otherwise return `dp[sum]`.
7. This approach ensures that all possible combinations of coins are considered efficiently to determine the minimum number needed for the target sum.
*/

class Solution {
public:
    int minCoins(vector<int>& coins, int sum) {
        // code here
        int n = coins.size();
        vector<int> dp(sum + 1, INT_MAX); 
        dp[0] = 0; 

        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum]; 
    }
};