// Maximum Sum Subarray of Size at least K

/*
 *    1. The problem asks to find the maximum sum of any subarray with length at least k.
 *    2. Compute prefix sums so that subarray sums can be calculated quickly.
 *    3. For each index i ≥ k, consider subarray ending at i with length ≥ k.
 *    4. Track the minimum prefix sum seen up to index i-k to maximize current subarray sum.
 *    5. Formula: maxSum = max(maxSum, prefix[i] - minPrefix).
 *    6. This ensures we always respect the length ≥ k constraint.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<long long> prefix(n+1, 0);
        
        
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }
        
        long long maxSum = LLONG_MIN;
        long long minPrefix = 0;
        
        for (int i = k; i <= n; i++) {
            minPrefix = min(minPrefix, prefix[i-k]);
            maxSum = max(maxSum, prefix[i] - minPrefix);
        }
        
        return (int)maxSum;
    }
};

// Key Points
// 1. Uses prefix sums to compute subarray sums efficiently.
// 2. Ensures subarray length is at least k.
// 3. Tracks minimum prefix sum up to i-k.
// 4. Formula: prefix[i] - minPrefix gives max sum ending at i.
// 5. Runs in O(n) time with O(n) space.
// 6. Cleaner and more direct than hybrid Kadane approach.
// 7. Works for both positive and negative numbers.