/*
1. If the string is empty or starts with '0', return 0 as it's not decodable.
2. Use a DP array `dp` where `dp[i]` stores the number of ways to decode the first `i` digits.
3. Initialize `dp[0] = 1` (base case for empty string) and `dp[1] = 1` (if the first digit is valid).
4. Iterate from index 2 to `n`, checking if the current digit can be decoded alone (`dp[i-1]`).
5. Also, check if the last two digits form a valid number (10-26) and add `dp[i-2]`.
6. The transition formula is `dp[i] = dp[i-1] + dp[i-2]` if valid, ensuring all decoding possibilities.
7. Finally, return `dp[n]`, which stores the total ways to decode the entire string.
*/

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = arr.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};