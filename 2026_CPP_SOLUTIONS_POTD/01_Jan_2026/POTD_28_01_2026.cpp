/*
1. This function counts the number of subsets in 'arr' whose sum equals 'k'.
2. It uses dynamic programming with a 1D array 'dp' where dp[sum] stores ways to form sum.
3. Initialization: dp[0] = 1, meaning one way to form sum 0 (empty subset).
4. For each element 'num', update dp from right to left to avoid recomputation overlap.
5. Negative numbers are skipped since they don't fit the subset sum logic here.
6. Time Complexity: O(n * k), where n = size of array and k = target sum.
7. Space Complexity: O(k), since only a 1D dp array of size k+1 is used.
*/

class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<long long> dp(k+1, 0); 
        dp[0] = 1; 

        for(int num : arr) {
            if(num < 0) continue;
            for(int sum = k; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }
        return dp[k];
    }
};

// Key points:
// - Problem is a variation of subset sum, counting subsets instead of checking existence.
// - dp[sum] accumulates number of ways to reach sum using available elements.
// - Iterating backwards ensures each element is only used once per subset.
// - Skipping negatives avoids invalid states in this implementation.
// - Efficient solution with O(n*k) time and O(k) space complexities.
// - Returns dp[k], which is the total count of subsets summing to k.
