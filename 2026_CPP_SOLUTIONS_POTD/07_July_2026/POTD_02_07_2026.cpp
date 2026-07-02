// Subset with Sum Divisible by K

/*
 *    1. We are given an array and integer k.
 *    2. The task is to check if any subset sum is divisible by k.
 *    3. If array size is greater than or equal to k, pigeonhole principle guarantees divisibility.
 *    4. Otherwise, we use dynamic programming to track possible remainders modulo k.
 *    5. For each number, update reachable remainders by combining with previous states.
 *    6. If at any point remainder 0 is reachable, return true.
 *    7. Time Complexity: O(n*k), Space Complexity: O(k).
 */

class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (n >= k) return true;
        
        vector<bool> dp(k, false);
        
        for (int num : arr) {
            int rem = num % k;
            if (rem == 0) return true;
            
            vector<bool> nextDp = dp;
            nextDp[rem] = true;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i]) {
                    int newRem = (i + rem) % k;
                    if (newRem == 0) return true;
                    nextDp[newRem] = true;
                }
            }
            
            dp = move(nextDp);
        }
        
        return dp[0];
    }
};

// Key Points
// 1. Uses pigeonhole principle for quick check when n >= k.
// 2. Dynamic programming tracks possible remainders.
// 3. Each number contributes to new remainder states.
// 4. Early exit if remainder 0 is found.
// 5. Space optimized to O(k).
// 6. Handles both positive and negative numbers correctly with modulo.
// 7. Efficient for moderate n and k values.