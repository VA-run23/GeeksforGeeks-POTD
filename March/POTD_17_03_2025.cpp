/*
1. The code implements the subset sum problem to check if a subset of the array exists with a sum equal to the given target `sum`.
2. A dynamic programming (DP) table `dp[n+1][sum+1]` is created, where `dp[i][j]` is true if a subset of the first `i` elements can form the sum `j`.
3. The first column of the DP table is initialized to true because a sum of 0 is always achievable by taking an empty subset.
4. The main DP logic iterates through all array elements and possible sums, updating `dp[i][j]` based on whether the current element is included or excluded.
5. If the current element `arr[i-1]` is less than or equal to `j`, it considers two cases: excluding the element or including it to achieve the sum.
6. The value in `dp[n][sum]` at the end of the computation gives the final result—whether the target `sum` can be achieved using the array elements.
7. The code has a time complexity of O(n × sum) and space complexity of O(n × sum), making it efficient for moderately sized inputs.
*/

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};