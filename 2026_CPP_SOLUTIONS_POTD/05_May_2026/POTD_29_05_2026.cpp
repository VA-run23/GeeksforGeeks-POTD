// Count Digit Groupings of a Number

/*
 *    1. The problem asks to count valid groupings of digits in a string.
 *    2. A grouping is valid if the sum of digits in each group is non-decreasing.
 *    3. Dynamic Programming (DP) is used to solve this efficiently.
 *    4. dp[i][prevSum] stores the number of ways to partition from index i with previous sum = prevSum.
 *    5. Iterate backwards, trying all possible partitions and updating dp.
 *    6. Base case: at the end of the string, all partitions are valid.
 *    7. Time Complexity: O(n^2 * sum), Space Complexity: O(n * sum).
 */

class Solution {
  public:
    int validGroups(string &s) {
        // code here
        int n = s.size(), mxSum = 9*n;
        vector<vector<int>> dp(n + 1, vector<int>(mxSum + 1));
        for (int i = 0; i <= mxSum; i++) {
            dp[n][i] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int prevSum = 0; prevSum <= mxSum; prevSum++) {
                int currSum = 0;
                for (int j = i; j<n; j++) {
                    currSum += (s[j]-'0');
                    if (currSum >= prevSum) {
                        dp[i][prevSum] += dp[j + 1][currSum];
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};

// Key Points
// 1. Problem involves partitioning digits into valid groups.
// 2. Validity depends on non-decreasing group sums.
// 3. DP table tracks partitions by index and previous sum.
// 4. Base case ensures all partitions at the end are valid.
// 5. Iteration is backward to build solutions bottom-up.
// 6. Complexity grows with string length and digit sums.
// 7. Efficient compared to brute force recursion.