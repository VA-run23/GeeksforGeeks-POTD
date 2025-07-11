
/*
    1. This code counts the number of binary strings of length 'n' that contain at least one pair of consecutive 1s.
    2. The total number of binary strings of length 'n' is (1 << n), or 2^n.
    3. 'dp[i]' stores the number of valid binary strings of length 'i' that do NOT contain consecutive 1s.
    4. Valid strings without consecutive 1s follow a recurrence: dp[i] = dp[i - 1] + dp[i - 2].
    5. This recurrence mimics the Fibonacci series, modeling combinations ending in '0' and '10' patterns.
    6. Subtracting dp[n] from total strings (2^n) gives the count of strings with at least one pair of consecutive 1s.
    7. Time complexity is O(n) due to the loop; space complexity is O(n) for storing the dp array.
*/

class Solution {
  public:
    int countConsec(int n) {
        // code here
        vector<int> dp(n + 1);
        dp[0] = 1; 
        dp[1] = 2;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return (1 << n) - dp[n]; 
    }
};